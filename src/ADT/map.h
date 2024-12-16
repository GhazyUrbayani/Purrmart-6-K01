#ifndef MAP_H
#define MAP_H

#include "boolean.h"

#define Map_Max_Elements 50

typedef struct MapElement {
    char* nama_barang;
    int kuantitas_barang;
} MapElement;

typedef struct Map {
    MapElement MapElements[Map_Max_Elements];
    int neff;
} Map;

void initMap(Map* map);

boolean map_isEmpty(Map* map);
boolean map_isFull(Map* map);

int searchMap(Map* map, char* key);
boolean inMap(Map* map, char* key);
void insertMap(Map* map, char* key, int value);

void deleteFromMap(Map* map, char* key);

void updateMap(Map* map, char* key, int value);

int getValueMap(Map* map, char* key);

void printMap(Map* mapaddr);

#endif
