# include <stdio.h>
# include "../ADT/map.h"
# include "../ADT/listdinamis.h"
# include "../ADT/mesinkata/mesinkata.h"
# include "../structs/item.h"


int getItemPrice(char* item, DList *item_list){
    int price;
    for (int i = 0; i < item_list->size; i++){
        Item* currItem = id_getItem(item_list, i);
        currentWord = stringToWord(currItem->name);
        if (WordEqual(stringToWord(item))){
            price = currItem->price;
            return price;
        }
    }
}
void showCart(Map* keranjang){
    if (map_isEmpty(keranjang)){
        printf("Keranjang kosong\n");
    } else {
        printf("Isi keranjang:\n");
        printf("No | Nama Barang | Kuantitas | Subtotal\n");
        int total = 0;
        for (int i = 0; i < keranjang->neff; i++){
            char* nama_barang = keranjang->MapElements[i].nama_barang;
            int kuantitas_barang = keranjang->MapElements[i].kuantitas_barang;
            int harga_barang = getItemPrice(nama_barang, item_list); // dapet dr list mana pls, namanya apah
            int subtotal = harga_barang * kuantitas_barang;
            total += subtotal;
            printf("%d. %s | %d | %d\n", i+1, nama_barang, kuantitas_barang, subtotal);
        }
        printf("Total biaya yang harus dikeluarkan adalah %d\n", total);
    }
}