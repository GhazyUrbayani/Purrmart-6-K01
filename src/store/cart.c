#include "cart.h"
#include "./../ADT/utils.h"

void cartAdd(Map* keranjang_user, char* namabarang, int kuantitas, DList* store_items) {
    if (id_search(store_items,namabarang) != -1) {
        // Item ada di toko
        int lokasi_item = searchMap(keranjang_user,namabarang);
        if (lokasi_item != -1) {
            // Item ada di keranjang
            int kuantitas_now = getValueMap(keranjang_user, namabarang);
            kuantitas_now += kuantitas;
            updateMap(keranjang_user,namabarang,kuantitas_now);
            printf("Jumlah %s berhasil di-update menjadi %d!\n",namabarang,kuantitas_now);
        } else {
            // Item tidak ada di keranjang
            insertMap(keranjang_user,namabarang,kuantitas);
            printf("%d %s berhasil ditambah ke keranjang!\n",kuantitas,namabarang);
        }
    } else {
        // Item tidak ada di toko
        printf("Barang (%s) tidak ada di toko!\n", namabarang);
    }
}

void cartRemove(Map* keranjang_user, char* namabarang, int kuantitas) {
    int lokasi_barang = searchMap(keranjang_user,namabarang);
    if (lokasi_barang != -1) {
        // Barang ada di keranjang
        // if jumlah kurang dari sama dengan keranjang
        // else if sama dengan keranjang
        // else jika lebih dari keranjang
        MapElement barang = keranjang_user->MapElements[lokasi_barang];
        if (barang.kuantitas_barang > kuantitas) {
            keranjang_user->MapElements[lokasi_barang].kuantitas_barang -= kuantitas;
            printf("Berhasil mengurangi %d %s dari keranjang belanja!\n",kuantitas,namabarang);
        } else if (barang.kuantitas_barang == kuantitas) {
            deleteFromMap(keranjang_user,namabarang);
            printf("Berhasil menghapus %s dari keranjang belanja!\n",namabarang);
        } else {
            printf("Tidak berhasil mengurangi, hanya terdapat %d %s pada keranjang!\n", barang.kuantitas_barang, namabarang);
        }

    } else {
       // Barang tidak ada di keranjang
       printf("Tidak ada %s di keranjang!\n",namabarang);
    }
}

void cartShow(Map* keranjang_user, DList* item_store) {
    if (keranjang_user->neff == 0) {
        printf("Keranjang kamu kosong!\n");
    } else {
        printf("\n===================== Isi Keranjangmu =====================\n");
        printf("%-5s %-20s %-10s\n", "Qty", "Nama Barang", "Total");
        printf("----------------------------------------------------------\n");

        int total_harga = 0;
        for (int i = 0; i < keranjang_user->neff; i++) {
            MapElement currentBarang = keranjang_user->MapElements[i];
            int harga = id_getItem(item_store, id_search(item_store, currentBarang.nama_barang))->price;
            int total = currentBarang.kuantitas_barang * harga;

            printf("%-5d %-20s %-10d\n", 
                   currentBarang.kuantitas_barang, 
                   currentBarang.nama_barang, 
                   total);

            total_harga += total;
        }

        printf("----------------------------------------------------------\n");
        printf("Total Biaya: %d\n", total_harga);
        printf("==========================================================\n");
    }
}

void cartPay(Map* keranjang_user, Stack* riwayat_user, int* uang_user, DList* store_items) {
    if (map_isEmpty(keranjang_user)) {
        printf("Keranjang kamu kosong!\n");
    } else {
        printf("\n=========================================================================\n");
        printf("                            Barang yang akan dibeli                      \n");
        printf("=========================================================================\n");
         printf("Qty         Nama Barang                  Total\n");
        printf("-------------------------------------------------------------------------\n");

        int total_harga = 0;
        for (int i = 0; i < keranjang_user->neff; i++) {
            MapElement currentBarang = keranjang_user->MapElements[i];
            int harga = id_getItem(store_items, id_search(store_items, currentBarang.nama_barang))->price;

            printf("%-11d %-30s %-10d\n", 
                   currentBarang.kuantitas_barang, 
                   currentBarang.nama_barang, 
                   currentBarang.kuantitas_barang * harga);

            total_harga += currentBarang.kuantitas_barang * harga;
        }
        printf("-------------------------------------------------------------------------\n");
        printf("Total biaya yang harus dikeluarkan adalah: %d. Apakah jadi dibeli? (Ya/Tidak): ", total_harga);
        STARTWORDINPUT();
        if (WordEqual(stringToWord("Ya"))) {
            if (*uang_user >= total_harga) {
                // Find max
                char* barangtermahal = transaksi_termahal(keranjang_user,store_items);
                
                // Push stack
                int kuantitastermahal = getValueMap(keranjang_user,barangtermahal);
                int hargatermahal = id_getItembyName(store_items,barangtermahal)->price;
                Riwayat max_history = newRiwayat(barangtermahal,kuantitastermahal * hargatermahal);
                stack_push(riwayat_user,max_history);
                
                // Clear Map
                initMap(keranjang_user);
                
                // Kurangi uang user
                *uang_user -= total_harga;
                printf("Transaksi berhasil!\n");
            } else {
                // Gagal beli: gak ada duit
                printf("Uang kamu tidak cukup!\n");
            }
        } else {
            printf("Transaksi gagal!\n");
            return;
        }
    }
}

char* transaksi_termahal(Map* keranjang_belanja, DList* toko_barang) {
    if (map_isEmpty(keranjang_belanja)) {
        printf("Map kosong!\n");
        return NULL;
    } else {
        char* barangbiggest = NULL;
        int max = 0;
        for (int i = 0; i < keranjang_belanja->neff; i++) {
            MapElement barang_keranjang = keranjang_belanja->MapElements[i];
            Item* barang_toko = id_getItembyName(toko_barang,barang_keranjang.nama_barang);
            int total = barang_keranjang.kuantitas_barang * barang_toko->price;
            if (total > max) {
                max = total;
                barangbiggest = barang_keranjang.nama_barang;
            } else if (total == max) {
                if (*barang_keranjang.nama_barang > *barangbiggest) {
                    barangbiggest = barang_keranjang.nama_barang;
                }
            }
        }
        return str_copy(barangbiggest);
    }
}