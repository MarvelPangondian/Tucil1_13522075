# Tugas kecil 1 Strategi Algoritma
> Program untuk mencari sekuens optimal pada *hacking minigame cyberpunk 2077*

## Daftar Isi
- [Tugas kecil 1 Strategi Algoritma](#tugas-kecil-1-strategi-algoritma)
  - [Daftar Isi](#daftar-isi)
  - [Sistematika File](#sistematika-file)
  - [Deskripsi Program](#deskripsi-program)
  - [Requirements](#requirements)
  - [Menjalankan Program](#menjalankan-program)
  - [Status Proyek](#status-proyek)
  - [Identitas Pembuat Program](#identitas-pembuat-program)

<!-- * [License](#license) -->
## Sistematika File
```
├─── bin
│       ├─── mainLinux
│       └─── mainWindows.exe
│
├─── doc
│       ├─── Tucil1_K1_13522075_Marvel Pangondian.pdf
│       └─── Tucil1-2024.pdf
│
├─── src
│       ├─── cyberpunk.cpp
│       ├─── cyberpunk.hpp
│       ├─── IO.cpp
│       ├─── IO.hpp
│       └─── main.cpp
│
├─── test
│       ├─── brutal.txt
│       ├─── brutalSolution.txt
│       ├─── test1.txt
│       ├─── test1Solution.txt
│       ├─── test2.txt
│       ├─── test2Solution.txt
│       ├─── test3.txt
│       ├─── test3Solution.txt
│       ├─── test4.txt
│       ├─── test4Solution.txt
│       ├─── test5.txt
│       ├─── test5Solution.txt
│       ├─── test6.txt
│       ├─── test6Solution.txt
│       ├─── test7.txt
│       ├─── test7Solution.txt
│       ├─── test8.txt
│       └─── test8Solution.txt
│
├─── .gitignore
├─── LICENSE
├─── README.md
├─── run.bat
└─── run.sh
```

## Deskripsi Program
 Program untuk mencari sekuens optimal pada permainan *hacking minigame cyberpunk 2077*. Program menggunaan algoritma *brute force* untuk mencari setiap kombinasi sekuens pada matrix token, lalu mencari sekuens yang paling optimal. Token pertama pada sekuens harus berada pada baris pertama, untuk token kedua harus berada pada kolom yang sama dengan token pertama, untuk token ketiga harus berada pada baris yang sama dengan token kedua, dst (pola horizontal, vertikal, horizontal, vertikal, ...). Sekuens yang dipilih tidak boleh melibihi buffer yang sudah ditentukan sebelumnya. Hasil akhir berupa poin maksimal, sekuens paling optimal, serta koordinat setiap token pada sekuens tersebut. 

## Requirements
* GCC compiler (versi 11.4.0 atau yang lebih baru) 

## Menjalankan Program
Pada *windows powershell*, pastikan berada pada *root directory* lalu jalankan run.bat
```
./run.bat
```
pada *ubuntu(WSL)*, pastikan berada pada *root directory* lalu jalankan :
```
$ chmod +x run.sh
$ ./run.sh
```
kedua cara di atas akan otomatis menghasilkan dan menjalankan executable file. Berikut adalah tampiilan program utama :
```
=========================== MAIN MENU ===========================
INPUT OPTIONS : 
1.Text file
2.Command Line
3.Exit
input : 
```
Untuk pilihan 1, pastikan .txt file berada pada folder test dengan format berikut :

```
buffer_size
jumlah_kolom jumlah_baris
matrix
number_of_sequences
sequences_1
sequences_1_reward
sequences_2
sequences_2_reward
…
sequences_n
sequences_n_reward
```
Hasil akhir program, jika diinginkan, dapat disimpan. File hasil akhir akan disimpan pada folder test

## Status Proyek
Status : *Completed*
| Poin  | Ya | Tidak |
|---|---|---|
| Program berhasil dikompilasi tanpa kesalahan | ✓ |   |
| Program berhasil dijalankan | ✓ |   |
| Program dapat membacamasukan berkas .txt | ✓ |   |
| Program dapat menghasilkan masukan secara acak | ✓ |  |
| Solusi yang diberikan program optimal| ✓ |  |
| Program dapat menyimpan solusi dalam berkas .txt | ✓ |  |
| Program memiliki GUI (Bonus) |  |   ✓ |

## Identitas Pembuat Program
Nama : Marvel Pangondian </br>
NIM : 13522075 </br>
Program Studi : Teknik Informatika </br>
Profile Github : [MarvelPangondian](https://github.com/MarvelPangondian)
<!-- Optional -->
<!-- ## License -->
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->
