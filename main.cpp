// ARIF SAPUTRA
// A11.2021.13480
// A11.43UG1

// KALKULATOR MATRIKS

#include <iostream>
#include <conio.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Variabel Global
int ordo;
int matriksA[6][6], matriksB[6][6];

// Fungsi Input Matriks
void inputMatriks(int matriks[][6]){
    for(int i=0; i<ordo; i++){
        for(int j=0; j<ordo; j++){
            cin >> matriks[i][j];
        }
    }
}

// Fungsi Cetak Matriks
template <class C> void cetakMatriks(C matriks[][6]){
    for(int i=0; i<ordo; i++){
        for(int j=0; j<ordo; j++){
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi Pilih Matriks
string pilihMatriks(){
    string pilih;
    cout << endl << "Pilih Matriks [A/B]: "; cin >> pilih;
    return pilih;
}

// Fungsi Edit Matriks
void editMatriks(){
    string pilihEdit;
    cout << endl << "Ingin Edit Matriks [A/B/ALL]: "; cin >> pilihEdit;
    if(pilihEdit=="A"){
        cout << "Masukkan Matriks A:" << endl;
        inputMatriks(matriksA);
    }else if(pilihEdit=="B"){
        cout << "Masukkan Matriks B:" << endl;
        inputMatriks(matriksB);
    }else if(pilihEdit=="ALL"){
        cout << "Masukkan Matriks A:" << endl;
        inputMatriks(matriksA);
        cout << endl;
        cout << "Masukkan Matriks B:" << endl;
        inputMatriks(matriksB);
    }else{
        cout << "Pilihan Anda Salah!";
    }
}

// Fungai Penjumlahan Matriks
void penjumlahan(){
    cout << endl << "Penjumlahan dari Matriks: " << endl << endl;
    cout << "Matriks A: " << endl;
    cetakMatriks(matriksA);
    cout << endl;
    cetakMatriks(matriksB);
    cout << endl << "Hasilnya Adalah: " << endl;
    for(int i=0; i<ordo; i++){
        for(int j=0; j<ordo; j++){
            // Menampilkan matriks setelah ditambah
            cout << matriksA[i][j] + matriksB[i][j];
            cout << "   ";
        }
        cout << endl;
    }
}

// Fungsi Pengurangan Matriks
void pengurangan(){
    cout << endl << "Pengurangan dari Matriks: " << endl << endl;
    cetakMatriks(matriksA);
    cout << endl;
    cetakMatriks(matriksB);
    cout << endl << "Hasilnya Adalah: " << endl;
    for(int i=0; i<ordo; i++){
        for(int j=0; j<ordo; j++){
            // Menampilkan matriks setelah dikurangi
            cout << matriksA[i][j] - matriksB[i][j];
            cout << "\t";
        }
        cout << endl;
    }
}

// Fungsi Perkalian Matriks
void perkalian(){
    cout << endl << "Perkalian dari Matriks: " << endl << endl;
    cetakMatriks(matriksA);
    cout << endl;
    cetakMatriks(matriksB);
    cout << endl << "Hasilnya Adalah: " << endl;
    for(int i=0; i<ordo; i++){
        for(int j=0; j<ordo; j++){
            // Nilai awal hasil adalah 0
            int hasil=0;
            // Looping untuk mengalikan matriks sesuai dengan indexnya
            for(int k=0; k<ordo; k++){
                // Menyimpan hasil perkalian matriks di variabel hasil
                hasil += (matriksA[i][k] * matriksB[k][j]);
            }
            // Menampilkan hasil perkalian
            cout << hasil << "\t";
        }
        cout << endl;
    }
}

// Fungsi Kalikan Matriks dengan Bilangan Desimal
void kalikan(int matriks[6][6], int x){
    for(int i=0; i<ordo; i++){
        for(int j=0; j<ordo; j++){
            // Menampilkan matriks setelah dikalikan
            cout << matriks[i][j] * x << "\t";
        }
        cout << endl;
    }
}

// Fuungsi pembantu untuk menentukan co-factor dari matriks
void getCofactor(int matriks[6][6], int temp[6][6], int p, int q, int n)
{
    int i=0, j=0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                // Menyimpan nilai matriks di variabel temp
                temp[i][j++] = matriks[row][col];
                if (j == n-1) {
                    // Reset nilai kolom
                    j=0;
                    // Increment nilai baris
                    i++;
                }
            }
        }
    }
}

// Fungsi Determinan Matriks
int determinan(int matriks[][6], int n){
    int det = 0;
    if (n == 1) {
        return matriks[0][0];
    }
    if (n == 2) {
        return (matriks[0][0]*matriks[1][1]) - (matriks[0][1]*matriks[1][0]);
    }
    int temp[6][6], sign=1;
    for (int i=0; i<n; i++) {
        // Mencari nilai co-factor dari matriks
        getCofactor(matriks, temp, 0, i, n);
        // Menambahkan setiap nilai hasil perhitungan ke variabel det
        det += sign * matriks[0][i] * determinan(temp, n-1);
        // Mengubah nilai penanda menjadi -
        sign = -sign;
   }
   return det;
}

// Fungsi Transpose Matriks
void transpose(int matriks[][6]){
    for(int i=0; i<ordo; i++){
        for(int j=0; j<ordo; j++){
            // Menampilkan matriks transpose
            cout << matriks[j][i] << "\t";
        }
        cout << endl;
    }
}

void adjoin(int matriks[][6], int adj[][6])
{
    if (ordo == 1) {
        adj[0][0] = 1;
        return;
    }
    int temp[6][6], sign=1;
    for (int i = 0; i < ordo; i++) {
        for (int j = 0; j < ordo; j++) {
            // Mencari nilai co-factor dari matriks
            getCofactor(matriks, temp, i, j, ordo);
            // Kondisi untuk nilai sign
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            // Tukar baris dan kolom untuk mendapatkan transpos matriks kofaktor
            adj[j][i] = (sign) * (determinan(temp, ordo-1));
        }
    }
}

bool inverse(int matriks[][6], float inverse[6][6])
{
    // Mencari nilai determinan
    int det = determinan(matriks, ordo);
    if (det == 0) {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }
    // Mencari Nilai Adjoin
    int adj[6][6];
    adjoin(matriks, adj);
    // Mencari Invers Menggunakan Rumus "inverse(matriks) = adj(matriks)/det(matriks)"
    for (int i = 0; i < ordo; i++){
        for (int j = 0; j < ordo; j++){
            inverse[i][j] = adj[i][j] / float(det);
        }
    }
    // Mengembalikan Nilai True
    return true;
}

void kalkulasiMatriks(){
    int pilihKalkulasi;
    string pm; 
    do{
        system("cls");
        cout << "--------------------------------" << endl;
        cout << "--  1. Penjumlahan            --" << endl;
        cout << "--  2. Pengurangan            --" << endl;
        cout << "--  3. Perkalian              --" << endl;
        cout << "--  4. Kalikan                --" << endl;
        cout << "--  5. Determinan             --" << endl;
        cout << "--  6. Transpose              --" << endl;
        cout << "--  7. Adjoin                 --" << endl;
        cout << "--  8. Invers                 --" << endl;
        cout << "--  9. Kembali                --" << endl;
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "  Pilihan Anda [1-9]: "; cin >> pilihKalkulasi; 
        cout << endl;

        switch (pilihKalkulasi){
            case 1: system("cls");
                penjumlahan();
                break;
            case 2: system("cls");
                pengurangan();
                break;
            case 3: system("cls");
                perkalian();
                break;
            case 4: system("cls");
                pm = pilihMatriks();
                int bilanganDesimal;
                cout << "Kalikan: "; cin >> bilanganDesimal;
                cout << endl;
                if(pm=="A"){
                    cout << "Matriks A: " << endl;
                    cetakMatriks(matriksA);
                    cout << endl << "Dikalikan Dengan " << bilanganDesimal << endl;
                    cout << endl << "Hasilnya Adalah: " << endl;
                    kalikan(matriksA, bilanganDesimal);
                }else if(pm=="B"){
                    cout << "Matriks B: " << endl;
                    cetakMatriks(matriksB);
                    cout << endl << "Dikalikan Dengan " << bilanganDesimal << endl;
                    cout << endl << "Hasilnya Adalah: " << endl;
                    kalikan(matriksB, bilanganDesimal);
                }else{
                    cout << endl << "Pilihan Anda Salah!";
                }
                break;
            case 5: system("cls");
                pm = pilihMatriks();
                if(pm=="A"){
                    cout << "Determinan dari " << endl;
                    cout << "Matriks A: " << endl;
                    cetakMatriks(matriksA);
                    cout << endl << "Hasilnya Adalah: " << endl;
                    cout << determinan(matriksA, ordo);
                }else if(pm=="B"){
                    cout << "Determinan dari " << endl;
                    cout << "Matriks B: " << endl;
                    cetakMatriks(matriksB);
                    cout << endl << "Hasilnya Adalah: " << endl;
                    cout << determinan(matriksB, ordo);
                }else{
                    cout << endl << "Pilihan Anda Salah!";
                }
                break;
            case 6: system("cls");
                pm = pilihMatriks();
                if(pm=="A"){
                    cout << "Transpose dari " << endl;
                    cout << "Matriks A: " << endl;
                    cetakMatriks(matriksA);
                    cout << endl << "Hasilnya Adalah: " << endl;
                    transpose(matriksA);
                }else if(pm=="B"){
                    cout << "Transpose dari " << endl;
                    cout << "Matriks B: " << endl;
                    cetakMatriks(matriksB);
                    cout << endl << "Hasilnya Adalah: " << endl;
                    transpose(matriksB);
                }else{
                    cout << endl << "Pilihan Anda Salah!";
                }
                break;
            case 7: system("cls");
                int adj[6][6];
                pm = pilihMatriks();
                if(pm=="A"){
                    cout << "Adjoin dari " << endl;
                    cout << "Matriks A: " << endl;
                    cetakMatriks(matriksA);
                    cout << endl << "Hasilnya Adalah: " << endl;
                    adjoin(matriksA, adj);
                    cetakMatriks(adj);
                }else if(pm=="B"){
                    cout << "Adjoin dari " << endl;
                    cout << "Matriks B: " << endl;
                    cetakMatriks(matriksB);
                    cout << endl << "Hasilnya Adalah: " << endl;
                    adjoin(matriksB, adj);
                    cetakMatriks(adj);
                }else{
                    cout << endl << "Pilihan Anda Salah!";
                }
                break;
            case 8: system("cls");
                float inv[6][6];
                pm = pilihMatriks();
                if(pm=="A"){
                    cout << "Invers dari " << endl;
                    cout << "Matriks A: " << endl;
                    cetakMatriks(matriksA);
                    cout << endl << "Hasilnya Adalah: " << endl;
                    inverse(matriksA, inv);
                    cetakMatriks(inv);
                }else if(pm=="B"){
                    cout << "Invers dari " << endl;
                    cout << "Matriks B: " << endl;
                    cetakMatriks(matriksB);
                    cout << endl << "Hasilnya Adalah: " << endl;
                    inverse(matriksB, inv);
                    cetakMatriks(inv);
                }else{
                    cout << endl << "Pilihan Anda Salah!";
                }
                break;
        }
        getch();
    }while(pilihKalkulasi!=9);
}

int main(){
    system("cls");

    cout << "Ordo Matriks: "; cin >> ordo;


    int pilihMenu;
    do{
        system("cls");
        cout << "--------------------------------" << endl;
        cout << "------ Kalkulator Matriks ------" << endl;
        cout << "--------------------------------" << endl;
        cout << "--  1. Input Matriks A dan B  --" << endl;
        cout << "--  2. Cetak Matriks A dan B  --" << endl;
        cout << "--  3. Edit Matriks A atau B  --" << endl;
        cout << "--  4. Edit Ordo Matriks      --" << endl;
        cout << "--  5. Kalkulasi Matriks      --" << endl;
        cout << "--  6. Keluar                 --" << endl;
        cout << "--------------------------------" << endl;
        cout << endl;
        cout << "  Pilihan Anda [1-6]: "; cin >> pilihMenu; 
        cout << endl;

        switch (pilihMenu){
            case 1: system("cls");
                cout << "Masukkan Matriks A:" << endl;
                inputMatriks(matriksA);
                cout << endl;
                cout << "Masukkan Matriks B:" << endl;
                inputMatriks(matriksB);
                break;
            case 2: system("cls");
                cout << "Matriks A:" << endl;
                cetakMatriks(matriksA);
                cout << endl;
                cout << "Matriks B:" << endl;
                cetakMatriks(matriksB);
                break;
            case 3: system("cls");
                editMatriks();
                break;
            case 4: system("cls");
                cout << "Masukkan Ordo Matriks: ";
                cin >> ordo;
                break;
            case 5: system("cls");
                kalkulasiMatriks();
                break;
        }
        getch();
    }while(pilihMenu!=6);

    return 0;
}