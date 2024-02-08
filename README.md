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
│       ├─── main
│       └─── main.exe
│
├─── doc
│       └───  
│
├─── src
│       ├─── cyberpunk.cpp
│       ├─── cyberpunk.hpp
│       ├─── IO.cpp
│       ├─── IO.hpp
│       ├─── main.cpp
│
├─── test
│       ├─── test1.txt
│       ├─── test1Solution.txt
│
├─── .gitignore
├─── README.md
├─── run.bat
└─── run.sh
```

## Deskripsi Program
 Program untuk mencari sekuens optimal pada permainan *hacking minigame cyberpunk 2077*. Program menggunaan algoritma *brute force* untuk mencari setiap kombinasi sekuens pada matrix token, lalu mencari sekuens yang paling optimal. Token pertama pada sekuens harus berada pada baris pertama, untuk token kedua harus berada pada kolom yang sama dengan token pertama, untuk token ketiga harus berada pada baris yang sama dengan token kedua, dst (pola horizontal, vertikal, horizontal, vertikal, ...). Sekuens yang dipilih tidak boleh melibihi buffer yang sudah ditentukan sebelumnya. Hasil akhir berupa poin maksimal, sekuens paling optimal, serta koordinat setiap token pada sekuens tersebut. 

## Requirements
* C++ 17
* GCC compiler (versi 11.4.0 atau yang lebih baru)

## Menjalankan Program
Pada *windows*, pastikan berada pada *root directory* lalu jalankan run.bat
```
./run.bat
```
pada *linux*, pastikan berada pada *root directory* lalu jalankan :
```
$ chmod +x run.sh
$ ./run.sh
```
kedua cara di atas akan otomatis menghasilkan dan menjalankan executable file.


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
