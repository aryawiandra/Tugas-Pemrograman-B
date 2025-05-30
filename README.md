# Kelompok 4 - Perhitungan Dosis Obat Menggunakan Metode Newton-Raphson Berbasis C++

## Daftar Anggota Kelompok
- **Gede Rama Pradya Widadga** (2306161914)
- **Maharaka Fadhilah** (2306225520)
- **Muhammad Arya Wiandra Utomo** (2306218295)
- **Muhammad Rifat Faqih** (2306250762)

## Deskripsi Program

Program ini merupakan implementasi metode numerik **Newton-Raphson** menggunakan bahasa pemrograman **C++** untuk menghitung dosis obat yang diperlukan agar mencapai **konsentrasi target dalam tubuh**. Perhitungan ini didasarkan pada model **farmakokinetik satu-kompartemen tanpa absorpsi**, dengan parameter:
- **ke**: konstanta eliminasi (per jam)
- **Vd**: volume distribusi (liter)
- **Ctarget**: konsentrasi target (mg/L)
- **t**: waktu pengukuran (jam)

Program dikembangkan dengan pendekatan **berorientasi objek (OOP)** menggunakan kelas `DrugDosageCalculator`, yang menangani input, proses iterasi Newton-Raphson, dan validasi. Iterasi dilakukan hingga nilai galat lebih kecil dari `10^-6`, dan hasil konvergen biasanya tercapai dalam 3–5 iterasi.

Program juga mencetak hasil per iterasi dalam bentuk tabel serta menyediakan validasi input. Berbagai skenario pengujian telah dilakukan untuk memastikan stabilitas dan akurasi metode dalam berbagai kondisi farmakokinetik.

### Fitur Utama:
- Perhitungan numerik dosis berbasis Newton-Raphson
- Validasi parameter farmakokinetik
- Output tabel hasil iterasi
- Akurasi tinggi dengan hasil cepat konvergen
- Desain OOP modular

### Rencana Pengembangan:
- Antarmuka grafis (GUI) untuk pengguna non-teknis
- Simulasi multi-dosis
- Integrasi dengan data klinis atau basis data pasien
