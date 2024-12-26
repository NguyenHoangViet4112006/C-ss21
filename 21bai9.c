#include <stdio.h>
struct Book{
    char maSach[20];
    char tenSach[100];
    char tacGia[100];
    float giaTien;
    char theLoai[50];
};
void nhapThongTinSach(struct Book books[], int *soLuong);
void luuThongTinSach(struct Book books[], int soLuong, char *filename);
void layThongTinSach(struct Book books[], int *soLuong, char *filename);
void hienThiThongTinSach(struct Book books[], int soLuong);
int main(){
    struct Book books[100];
    int soLuong=0;
    int luaChon;
    char filename="sach.bin";
    do{
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon){
            case 1:
                nhapThongTinSach(books, &soLuong);
                break;
            case 2:
                luuThongTinSach(books, soLuong, filename);
                break;
            case 3:
                layThongTinSach(books, &soLuong, filename);
                break;
            case 4:
                hienThiThongTinSach(books, soLuong);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 5);
    return 0;
}
void nhapThongTinSach(struct Book books[], int *soLuong) {
    printf("Nhap so luong sach: ");
    scanf("%d", soLuong);
    for (int i = 0; i < *soLuong; i++) {
        printf("Nhap thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", books[i].maSach);
        printf("Ten sach: ");
        getchar();
        fgets(books[i].tenSach, sizeof(books[i].tenSach), stdin);
        books[i].tenSach[strcspn(books[i].tenSach, "\n")] = ' ';
        printf("Tac gia: ");
        fgets(books[i].tacGia, sizeof(books[i].tacGia), stdin);
        books[i].tacGia[strcspn(books[i].tacGia, "\n")] = ' ';
        printf("Gia tien: ");
        scanf("%f", &books[i].giaTien);
        printf("The loai: ");
        getchar();
        fgets(books[i].theLoai, sizeof(books[i].theLoai), stdin);
        books[i].theLoai[strcspn(books[i].theLoai, "\n")] = ' ';
    }
}
void luuThongTinSach(struct Book books[], int soLuong, char *filename){
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    fwrite(&soLuong, sizeof(int), 1, file);
    fwrite(books, sizeof(struct Book), soLuong, file);
    fclose(file);
    printf("Da luu thong tin sach vao file.\n");
}
void layThongTinSach(struct Book books[], int *soLuong, char *filename){
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return;
    }
    fread(soLuong, sizeof(int), 1, file);
    fread(books, sizeof(struct Book), *soLuong, file);
    fclose(file);
    printf("Da lay thong tin sach tu file.\n");
}
void hienThiThongTinSach(struct Book books[], int soLuong){
    for (int i = 0; i < soLuong; i++) {
        printf("Thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].maSach);
        printf("Ten sach: %s\n", books[i].tenSach);
        printf("Tac gia: %s\n", books[i].tacGia);
        printf("Gia tien: %.2f\n", books[i].giaTien);
        printf("The loai: %s\n", books[i].theLoai);
    }
}
