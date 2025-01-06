#include <stdio.h>
#include <string.h>
#include "account.h"

void saveClientToFile(Client client[], int m) {
    FILE *file = fopen("clients.bin", "wb");
    if (file) {
        fwrite(client, sizeof(Client), m, file);
        fclose(file);
    }
}


void loadClientFromFile(Client client[], int *m) {
    FILE *file = fopen("clients.bin", "rb");
    if (file) {
        *m = 0;
        while (fread(&client[*m], sizeof(Client), 1, file)) {
            (*m)++;
        }
        fclose(file);
    }
}


void saveAdminToFile(Admin *admin) {
    FILE *file = fopen("accounts.bin", "wb");
    if (file) {
        fwrite(admin, sizeof(Admin), 1, file);
        fclose(file);
    }
}


void loadAdminFromFile(Admin *admin) {
    FILE *file = fopen("accounts.bin", "rb");
    if (file) {
        fread(admin, sizeof(Admin), 1, file);
        fclose(file);
    } else {
        
        strcpy(admin->username, "admin");
        strcpy(admin->password, "admin123");
        saveAdminToFile(admin);  
    }
}

void printfclient(Client client[], int m) {
    printf("\n_______________________________________________________________________________________________\n");
    printf("| %-2s | %-40s | %-20s | %-20s |\n", "ID", "Ten khach hang", "So dien thoai", "Ngay muon sach");
    printf("|____|__________________________________________|______________________|______________________|\n");
    for (int i = 0; i < m; i++) {
        printf("| %-2d | %-40s | %-20s | %-20s |\n", client[i].id, client[i].clientname, client[i].phonenumber, client[i].date);
    }
}

void addclient(Client client[], int *m) {
    getchar();
	client[*m].id=*m+1;
	while(1){
	printf("Moi nhap vao ten khach hang: \n");
	fgets(client[*m].clientname,100,stdin);
	client[*m].clientname[strcspn(client[*m].clientname, "\n")]='\0';
	if (strlen(client[*m].clientname)==0){
		printf("Ten khach hang khong duoc bo trong!!!\n");
		continue;
	}	
	break;
}
	while(1){
	printf("Moi nhap vao so dien thoai khach hang: \n");
	fgets(client[*m].phonenumber,50,stdin);
	client[*m].phonenumber[strcspn(client[*m].phonenumber,"\n")]='\0';
	if(strlen(client[*m].phonenumber)==0){
		printf("So dien thoai cua khach hang khong duoc bo trong!!!\n");
		continue;
	}
	break;
}
	while(1){
	printf("Moi nhap vao ngay muon sach: \n");
	fgets(client[*m].date,50,stdin);
	client[*m].date[strcspn(client[*m].date,"\n")]='\0';
	if(strlen(client[*m].date)==0){
		printf("Ngay muon sach khong duoc bo trong!!!\n");
		continue;
	}
	break;
}
	(*m)++;
	printf("Them khach hang thanh cong!!!\n");
}