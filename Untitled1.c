#include <stdio.h>
#include <string.h>

int gun;
char tarih[20], saat[20], doktor_adi[50];

struct hasta {
    char ad[50];
    char soyad[50];
    char tcno[12];
};

void ay_sec() {
    int ay;
    printf("Randevu Almak Istediginiz Ayi Tuslayiniz.\n");
    printf("Orn: Subat --> 2 \\ Ekim --> 10\n");
    scanf("%d", &ay);
    switch (ay) {
        case 1: strcpy(tarih, "Ocak"); break;
        case 2: strcpy(tarih, "Subat"); break;
        case 3: strcpy(tarih, "Mart"); break;
        case 4: strcpy(tarih, "Nisan"); break;
        case 5: strcpy(tarih, "Mayis"); break;
        case 6: strcpy(tarih, "Haziran"); break;
        case 7: strcpy(tarih, "Temmuz"); break;
        case 8: strcpy(tarih, "Agustos"); break;
        case 9: strcpy(tarih, "Eylul"); break;
        case 10: strcpy(tarih, "Ekim"); break;
        case 11: strcpy(tarih, "Kasim"); break;
        case 12: strcpy(tarih, "Aralik"); break;
        default: printf("Hatali Tuslama Yaptiniz. Tekrar Deneyiniz.\n"); return;
    }
}

int gun_sec() {
    int gun;
    printf("Randevunuzu Almak Istediginiz Gunu Tuslayiniz\n");
    printf("1 ile 30 arasi bir sayi tuslayiniz.\n");
    scanf("%d", &gun);
    if (gun >= 31) {
        printf("Hatali Gun Girisi Yaptiniz.\n");
        return 1;
    }
    return gun;
}

void randevusaati() {
    int saat_secim;
    printf("Randevu Almak Istediginiz Saati Giriniz.\n");
    printf("1) 8.00 - 8.30  2) 8.30 - 9.00  3) 9.00 - 9.30  4) 9.30 - 10.00\n");
    printf("5) 10.00 - 10.30  6) 10.30 - 11.00  7) 11.00 - 11.30  8) 11.30 - 12.00\n");
    printf("9) 13.00 - 13.30  10) 13.30 - 14.00  11) 14.00 - 14.30  12) 14.30 - 15.00\n");
    scanf("%d", &saat_secim);
    switch (saat_secim) {
        case 1: strcpy(saat, "8.00"); break;
        case 2: strcpy(saat, "8.30"); break;
        case 3: strcpy(saat, "9.00"); break;
        case 4: strcpy(saat, "9.30"); break;
        case 5: strcpy(saat, "10.00"); break;
        case 6: strcpy(saat, "10.30"); break;
        case 7: strcpy(saat, "11.00"); break;
        case 8: strcpy(saat, "11.30"); break;
        case 9: strcpy(saat, "13.00"); break;
        case 10: strcpy(saat, "13.30"); break;
        case 11: strcpy(saat, "14.00"); break;
        case 12: strcpy(saat, "14.30"); break;
        default: printf("Hatali Bir Secim Yaptiniz Lutfen Tekrar Deneyiniz.\n");
    }
}

void doktor_sec(int bolum) {
    int doktor;
    printf("Doktorunuzu Seciniz.\n");
    const char* doktorlar[10][3] = {
        {"Cevdet Yavuz", "Hamdi Cakmak", "Ismail Sagir"},
        {"Belgin Kucukyangoz", "Dilan Kizilirmak", "Fatma Bicici"},
        {"Ali Gurun", "Ayse Aktemur", "Harun Su"},
        {"Ahmet Kurtul", "Erkan Uysal", "Esef Imrek"},
        {"Fatma Uyar", "Harun Gizir", "Ismail Evgin"},
        {"Esra Alakus", "Enver Aytemiz", "Dilan Celik Elis"},
        {"Serkan Kurtul", "Serkan Urkmez", "Sedat Koroglu"},
        {"Yasar Bakis", "Ali Okur", "Mehmet Karsavul"},
        {"Gul Oruc", "Aytac Dinc", "Erdem Ozyurt"},
        {"Omer Uyar", "Selcuk Altin", "Yusuf Kaya"},
    };

    for (int i = 0; i < 3; i++) {
        printf("%d %s\n", i + 1, doktorlar[bolum - 1][i]);
    }
    scanf("%d", &doktor);
    if (doktor < 1 || doktor > 3) {
        printf("Hatali Tuslama Yaptiniz.\n");
        doktor_sec(bolum);
    } else {
        strcpy(doktor_adi, doktorlar[bolum - 1][doktor - 1]);
        gun = gun_sec();
        if (gun != -1) {
            ay_sec();
            randevusaati();
        }
    }
}

void fis_al(int gun) {
    printf("\n************ RANDEVU FISI ************\n");
    printf("Randevunuz: %d %s tarihinde, saat %s'dedir.\n", gun, tarih, saat);
    printf("Doktor: %s\n", doktor_adi);
    printf("\n");
}

int main() {
    printf("Randevu Alma Sistemine Hos Geldiniz.\n");
    struct hasta x;
    int bolum;

    printf("Adinizi Giriniz: ");
    scanf("%s", x.ad);
    printf("Soyadinizi Giriniz: ");
    scanf("%s", x.soyad);
    printf("TC kimlik numaranizi giriniz.\n");
    scanf("%d" , &x.tcno);

    printf("Randevu Almak Istediginiz Bolumu Seciniz.\n");
    printf("1) Beyin ve Sinir Cerrahisi\n");
    printf("2) Deri ve Zuhrevi Hastaliklari\n");
    printf("3) Enfeksiyon Hastaliklari ve Klinik Mikrobiyoloji\n");
    printf("4) Genel Cerrahi\n");
    printf("5) Goz Hastaliklari\n");
    printf("6) Ic Hastaliklari (Dahiliye)\n");
    printf("7) Kardiyoloji\n");
    printf("8) Kulak Burun Bogaz\n");
    printf("9) Noroloji\n");
    printf("10) Uroloji\n");
    scanf("%d", &bolum);

    if (bolum >= 1 && bolum <= 10) {
        doktor_sec(bolum);
        fis_al(gun);
    } else {
        printf("Hatali Secim Yaptiniz.\n");
    }

    return 0;
}
