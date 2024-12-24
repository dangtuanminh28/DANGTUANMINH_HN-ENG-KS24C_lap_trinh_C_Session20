#include<stdio.h>
#include<string.h>
struct Book {
    int id;                
    char name[100];        
    char author[100];      
    int price;             
};
int main() {
    int choice = 0;
	int position;
	int idSet = 1;
	int i, j;
    char findBook[100];
    struct Book shelf[100]; 
    int quantity = 0;       
    do {
        printf("\nMENU\n");
        printf("1.Nhap so luong va thong tin sach.\n");
        printf("2.Hien thi thong tin sach.\n");
        printf("3.Them sach vao vi tri.\n");
        printf("4.Xoa sach theo ma sach.\n");
        printf("5.Cap nhat thong tin sach theo ma sach.\n");
        printf("6.Sap xep sach theo gia tang dan.\n");
        printf("7.Tim kiem sach theo ten sach.\n");
        printf("8.Thoat.\n");
        printf("Moi nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Moi nhap so luong sach: ");
                scanf("%d", &quantity);
                if (quantity <= 0 || quantity > 100) {
                    printf("So luong khong hop le! Vui long nhap lai.\n");
                    break;
                }
                for (i = 0; i < quantity; i++) {
                    printf("Nhap thong tin cho sach ID %d:\n", idSet);
                    shelf[i].id = idSet++; 
                    printf("Ten sach: ");
                    while (getchar() != '\n'); 
                    fgets(shelf[i].name, sizeof(shelf[i].name), stdin);
                    shelf[i].name[strcspn(shelf[i].name, "\n")] = '\0'; 
                    printf("Ten tac gia: ");
                    fgets(shelf[i].author, sizeof(shelf[i].author), stdin);
                    shelf[i].author[strcspn(shelf[i].author, "\n")] = '\0';
                    printf("Gia sach: ");
                    scanf("%d", &shelf[i].price);
                    if (shelf[i].price < 0) {
                        printf("Gia sach khong hop le! Vui long nhap lai.\n");
                        i--;
                    }
                }
                break;
            case 2: 
                printf("\nDanh sach sach hien tai:\n");
                for (i = 0; i < quantity; i++) {
                    printf("\nThong tin sach ID %d:\n", shelf[i].id);
                    printf("Ten sach: %s\n", shelf[i].name);
                    printf("Ten tac gia: %s\n", shelf[i].author);
                    printf("Gia: %d $\n", shelf[i].price);
                }
                break;
            case 3: 
                printf("Nhap vi tri muon them (1-%d): ", quantity + 1);
                scanf("%d", &position);
                if (position < 1 || position > quantity + 1) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    position--; 
                    for (i = quantity; i > position; i--) {
                        shelf[i] = shelf[i - 1];
                    }
                    shelf[position].id = idSet++; 
                    printf("Nhap ten sach: ");
                    while (getchar() != '\n'); 
                    fgets(shelf[position].name, sizeof(shelf[position].name), stdin);
                    shelf[position].name[strcspn(shelf[position].name, "\n")] = '\0';
                    printf("Nhap ten tac gia: ");
                    fgets(shelf[position].author, sizeof(shelf[position].author), stdin);
                    shelf[position].author[strcspn(shelf[position].author, "\n")] = '\0';
                    printf("Nhap gia sach: ");
                    scanf("%d", &shelf[position].price);
                    if (shelf[position].price < 0) {
                        printf("Gia sach khong hop le! Khong them duoc.\n");
                    } else {
                        quantity++;
                    }
                }
                break;
            case 4: 
                printf("Nhap ID sach can xoa: ");
                scanf("%d", &position);
                int found = 0;
                for (i = 0; i < quantity; i++) {
                    if (shelf[i].id == position) {
                        found = 1;
                        for (j = i; j < quantity - 1; j++) {
                            shelf[j] = shelf[j + 1];
                        }
                        quantity--; 
                        printf("Da xoa sach co ID %d.\n", position);
                        break;
                    }
                }
                if (!found) {
                    printf("Khong tim thay sach co ID %d.\n", position);
                }
                break;
            case 5: 
                printf("Nhap ID sach can cap nhat: ");
                scanf("%d", &position);
                found = 0; 
                for (i = 0; i < quantity; i++) {
                	if (shelf[i].id == position) {
                		found = 1;
            			printf("Nhap ten sach moi: ");
            			while (getchar() != '\n');
            			fgets(shelf[i].name, sizeof(shelf[i].name), stdin);
            			shelf[i].name[strcspn(shelf[i].name, "\n")] = '\0';
            			printf("Nhap ten tac gia moi: ");
            			fgets(shelf[i].author, sizeof(shelf[i].author), stdin);
            			shelf[i].author[strcspn(shelf[i].author, "\n")] = '\0';
            			printf("Nhap gia moi: ");
            			scanf("%d", &shelf[i].price);
            		if (shelf[i].price < 0) {
                		printf("Gia sach khong hop le! Gia khong duoc cap nhat.\n");
            		} else {
               			printf("Da cap nhat thong tin sach co ID %d.\n", position);
            		}
            		break; 
        			}
    			}
    			if (!found) {
        			printf("Khong tim thay sach co ID %d.\n", position);
    			}
    			break;
            case 6: 
                for (i = 0; i < quantity - 1; i++) {
                    for (j = i + 1; j < quantity; j++) {
                        if (shelf[i].price > shelf[j].price) {
                            struct Book temp = shelf[i];
                            shelf[i] = shelf[j];
                            shelf[j] = temp;
                        }
                    }
                }
                printf("Danh sach da duoc sap xep theo gia tang dan.\n");
                break;
            case 7: 
                printf("Nhap ten sach can tim: ");
                while (getchar() != '\n');
                fgets(findBook, sizeof(findBook), stdin);
                findBook[strcspn(findBook, "\n")] = '\0';
                printf("Ket qua tim kiem:\n");
                found = 0;
                for (i = 0; i < quantity; i++) {
                    if (strcmp(shelf[i].name, findBook) == 0) {
                        printf("\nThong tin sach ID %d:\n", shelf[i].id);
                        printf("Ten sach: %s\n", shelf[i].name);
                        printf("Ten tac gia: %s\n", shelf[i].author);
                        printf("Gia: %d $\n", shelf[i].price);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay sach co ten '%s'.\n", findBook);
                }
                break;

            case 8: 
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);
    return 0;
}
