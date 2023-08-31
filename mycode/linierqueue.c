#include <stdio.h>
#include <conio.h>
#include <windows.h>

int antrian[7], i = 0, f = -1, r = -1, pil;

void gotoxy(int x, int y)
{
    // Input
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
    int ukuran = sizeof(antrian) / sizeof(antrian[0]);
ulang:
    system("cls");
    printf("ANTRIAN\n\n");
    printf("i\n");

    for (i = 0; i <= ukuran - 1; i++)
    {
        gotoxy(i * 3 + 5, 2);
        printf("%d", i);
    }
    printf("\nQ");
    for (i = 0; i <= ukuran - 1; i++)
    {
        gotoxy(i * 3 + 5, 3);
        printf("%d", antrian[i]);
    }

    printf("\n");
    printf("Front=%d, Rear=%d", f, r);
    if ((f == -1) && (r = -1))
    {
        printf("\nQUEUE dalam keadaan KOSONG");
    }
    else
    {
        printf("\n");
    }
    printf("\n\n");
    printf("PILIHAN:\n");
    printf("----------------\n");
    printf("1. Tambah Data\n");
    printf("2. Hapus Data\n");
    printf("3. Keluar\n");
    printf("----------------\n");
    printf("Pilihan: ");
    scanf("%d", &pil);
    printf("\n\n");

    if (pil == 1)
    {
        if (r == 6)
        {
            gotoxy(0, 5);
            printf("QUEUE dalam keadaan PENUH, PENYISIPAN DITOLAK!!");
            getchar();
            getchar();
        }

        if (r == ukuran - 1)
        {
            printf("ANTRIAN penuh!...Proses insert data tidak dapat dilakukan");
            goto ulang;
        }
        if (f < 0)
        {
            f = r = r + 1;
        }
        else
        {
            r = r + 1;
        }
        printf("Masukkan nilai data: ");
        scanf("%d", &antrian[r]);
        goto ulang;
    }
    else if (pil == 2)
    {
        if ((f == -1) && (r == -1))
        {
            gotoxy(0, 5);
            printf("QUEUE dalam keadaan KOSONG, PENGHAPUSAN DITOLAK!!");
            getchar();
            getchar();
        }

        antrian[f] = 0;
        f = f + 1;
        if (f > r)
        {
            f = -1;
            r = -1;
            goto ulang;
        }
        else
        {
            goto ulang;
        }
    }
    else
    {
        printf("\n\n");
        return 0;
    }
}
