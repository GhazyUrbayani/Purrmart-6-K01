#include "map.h"
#include "utils.h"
#include <stdio.h>

void initMap(Map* map) {
    map->neff = 0;
}

boolean map_isEmpty(Map* map) {
    return (map->neff == 0);
}

boolean map_isFull(Map* map) {
    return (map->neff == Map_Max_Elements);
}

int searchMap(Map* map, char* key) {
    if (map_isEmpty(map)) return -1;
    for (int i = 0; i < map->neff; i++) {
        MapElement current = map->MapElements[i];
        if (str_compare(current.nama_barang,key)) {
            return i;
        }
    }
    return -1;
}

boolean inMap(Map* map, char* key) {
    return searchMap(map,key) != -1 ? true : false;
}

void insertMap(Map* map, char* key, int value) {
    if (!inMap(map,key)) {
        map->MapElements[map->neff].nama_barang = str_copy(key);
        map->MapElements[map->neff].kuantitas_barang = value;
        map->neff++;
    }
}

void deleteFromMap(Map* map, char* key) {
    int element_location = searchMap(map,key);
    if (element_location != -1) {
        // Jika ada, maka dua kasus, berada di awal akhir atau lainnya.
        // Jika di akhir
        if (element_location == map->neff - 1) {
            char* nama = map->MapElements[element_location].nama_barang;
            map->MapElements[element_location].nama_barang = NULL;
            free(nama);
        } else {
            free(map->MapElements[element_location].nama_barang);
            while (element_location != map->neff - 1) {
                map->MapElements[element_location].nama_barang = map->MapElements[element_location+1].nama_barang;
                map->MapElements[element_location].kuantitas_barang = map->MapElements[element_location+1].kuantitas_barang;
                element_location++;
            }
        }
        map->neff--;
    }
}

void updateMap(Map* map, char* key, int value) {
    int element_location = searchMap(map, key);
    if (element_location != -1) {
        map->MapElements[element_location].kuantitas_barang = value;
    }
}

int getValueMap(Map* map, char* key) {
    int element_location = searchMap(map,key);
    if (element_location != -1) {
        return map->MapElements[element_location].kuantitas_barang;
    }
    else {
        fprintf(stderr,"Eror mengakses key yang tidak ada.\n");
    }
}

void printMap(Map* mapaddr) {
    if (map_isEmpty(mapaddr)) {
        printf("Map kosong!\n");
    } else {
        for (int i = 0; i < mapaddr->neff; i++) {
            MapElement current_map_element = mapaddr->MapElements[i];
            printf("%d %s\n", current_map_element.kuantitas_barang,current_map_element.nama_barang);
        }
    }
}