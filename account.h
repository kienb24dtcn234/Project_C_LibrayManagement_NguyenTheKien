#ifndef ACCOUNT_H
#define ACCOUNT_H


typedef struct {
    int id;
    char clientname[100];
    char phonenumber[50];
    char date[50];
    char category[50];
} Client;


typedef struct {
    char username[50];
    char password[50];
} Admin;

void addclient(Client client[], int *m);
void deleteclient(Client client[], int *m);
void findclient(Client client[], int m);
void printfclient(Client client[], int m);
void saveClientToFile(Client client[], int m);
void loadClientFromFile(Client client[], int *m);
void updateClient(Client client[], int m);
void saveAdminToFile(Admin *admin);
void loadAdminFromFile(Admin *admin);

#endif