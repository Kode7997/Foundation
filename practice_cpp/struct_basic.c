#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct info{
    char *mac;
    char *ip;
};

struct sysinfo {
    struct info *arr;
};

struct info* create_node(char *mac, char *ip){
    struct info *i = (struct info *)malloc(sizeof(struct info));

    i->mac = (char *)malloc(strlen(mac)+1);
    i->ip = (char *)malloc(strlen(ip)+1);
    
    strcpy(i->mac,mac);
    strcpy(i->ip, ip);

    return i;
}

void addEntry(struct sysinfo *info, char *mac, char *ip){
    for (int i = 0; i < 5; i++)
    {
       if (info->arr[i].mac == NULL){
           info->arr[i] = *create_node(mac, ip); // dereference of array
           break; 
       }
    }
    
}

int main(){

    struct sysinfo *sinfo = (struct sysinfo *)malloc(sizeof(struct sysinfo));
    int num = 5;
    sinfo->arr = (struct info *)malloc(num * sizeof(struct info));

    for(int i=0;i<num;i++){
        sinfo->arr[i].mac = NULL;
        sinfo->arr[i].ip = NULL;

    }

    addEntry(sinfo, "456345::459345:45345", "1281218128");
    addEntry(sinfo, "0x3y987234", "0x76245");

    for(int i=0;i<5;i++){
        if (sinfo->arr[i].mac != NULL){
            printf("mac: %s ip: %s\n", sinfo->arr[i].mac, sinfo->arr[i].ip);
        }
    }
}