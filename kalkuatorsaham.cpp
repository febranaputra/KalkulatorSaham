/*
Nama : I Gede Febrana Putra
NIM  : 2101020025
Prodi : Teknik Informatika
*/


#include <iostream>
using namespace std;

int main()
{
    int net_buy, net_sell;
    int menu, lot, lot_2, tot_lot, lembarshm;
    float price, price_2, tot_price, sellprice, profit_loss;
    float avg_price, persen_prof_loss, tot_value;
    menu :
    system("cls");
    cout << "\t\tKalkulator Saham\n\n";
    cout << "--------------------------------" << endl;
    cout << "1. Average Calculator \n";
    cout << "2. Profit Calculator \n";
    cout << "3. Compound Interest Calculator\n";
    cout << "4. Cash Divident Calculator\n";
    cout << "5. Exit\n";
    cout << "--------------------------------" << endl;
    cout << "Masukan Pilihan : ";
    cin >> menu;


    switch (menu) {
        case 1 : // average calculator - menu 1
        char pilih;
        avgcalculator:
        system ("cls") ; //clear screen pada terminal text editor
        cout << "===Average Calculator===" << endl; //menghitung averaging pembelian saham
        cout << "Masukan Data Pembelian Pertama " <<endl;
        cout << "Lot \t : ";
        cin >> lot;
        cout << "Buy Price : ";
        cin >> price;
        cout << "\nMasukan Data Pembelian Selanjutnya " << endl;
        cout << "Lot \t : ";
        cin >> lot_2;
        cout << "Buy Price :  ";
        cin >> price_2;
        cout << endl;

        tot_lot = lot + lot_2;
        tot_price  = (lot * price) + (lot_2 * price_2);
        avg_price = tot_price / tot_lot;
        tot_value = (tot_lot * 100) * avg_price; //1 lot = 100 lembar saham

        cout << "--------------------------------------------------" << endl;
        cout << "Total Lot     : " << tot_lot << endl;
        cout << "Average Price : " << avg_price << endl;
        cout << "Total Value   : " << "Rp." <<tot_value << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "[*Belum termasuk fee transaksi] \n\n";

        cout << "\nIngin menghitung lagi<y> atau kembali ke menu <n> : ";
        cin >> pilih;
        if (pilih == 'y' || pilih == 'Y'){
            goto avgcalculator;
        } else if (pilih == 'n' || pilih == 'N'){
            goto menu;
        }
        break;
        
        case 2: //profit calculator - menu 2
        profit:
        system ("cls");
        cout << "===Profit Calculator===" << endl; //menghitung keuntungan atau kerugian
        cout << "Jumlah Lot : ";
        cin  >> tot_lot ;
        cout << "Buy Price  : ";
        cin >> tot_price;
        cout << "Sell Price : ";
        cin >> sellprice;
        cout << endl;

        lembarshm = 100 * tot_lot ; // 1 lot = 100 lembar saham
        net_buy = tot_price * lembarshm ;
        net_sell = sellprice * lembarshm;
        profit_loss = net_sell - net_buy;
        persen_prof_loss = (profit_loss * 100) / net_buy; //persentase

        cout << "--------------------------------------------------" << endl;
        cout << "Net Amount Buy  : " << "Rp. " << net_buy << endl;
        cout << "Net Amount Sell : " << "Rp. " << net_sell << endl;
        cout << "Profit / Loss   : " << "Rp. " << profit_loss << endl;
        cout << "Persentase\t: " << persen_prof_loss << "% " << endl;
        cout << "--------------------------------------------------" << endl;

       cout << "\nIngin menghitung lagi<y> atau kembali ke menu <n> : ";
       cin >> pilih;
       if (pilih == 'y' || pilih == 'Y'){
            goto profit;
        } else if (pilih == 'n' || pilih == 'N'){
            goto menu;
        }
        break;

        case 3 :
        int tahun,nilai_sekarang, nilai_masdep, compound_interest;
        float bunga, suku_bunga, A, growth_rate, selisih;
        
        compoundinterest:
        system ("cls");
        cout << "===Compound Interest Calculator===" << endl;
        cout << "Nilai Uang Sekarang / Present Value    \n[Ex:100000]  : "; 
        cin >> nilai_sekarang;
        cout << "Suku Bunga per Tahun / Interest Rate (%) \n[Ex:15]    : "; 
        cin >> bunga;
        cout << "Jumlah Periode (Tahun) / Time of Period \n[*Pilih 3/5/10/15] : "; 
        cin >> tahun;
        cout << endl;

        //perhitungan compound interest tanpa library math.h
        // rumus compound_interest = nilai awal (( 1 + bunga/100)^tahun) - nilai awal
        suku_bunga = bunga / 100;
        A = (1 + suku_bunga) ; //deklarasi A agar
        cout << "--------------------------------------------------" << endl;
         if(tahun == 3){
         compound_interest = (nilai_sekarang * (A * A * A)) - nilai_sekarang; //jika 3 tahun maka A pangkat 3
         nilai_masdep = nilai_sekarang + compound_interest;
         selisih = (nilai_masdep - nilai_sekarang);
         growth_rate = selisih / nilai_sekarang * 100;
        cout << "Compound Interest \t\t: " << "Rp. " << compound_interest << endl;
        cout << "Nilai Masa Depan / Future Value : " << "Rp. " << nilai_masdep << endl;
        cout << "Growth Rate        \t\t: " << growth_rate << " % " << endl;
        } 
        else if (tahun == 5){
         compound_interest = (nilai_sekarang * (A * A * A * A * A)) - nilai_sekarang; //A pangkat 5
         nilai_masdep = nilai_sekarang + compound_interest;
         selisih = (nilai_masdep - nilai_sekarang);
         growth_rate = selisih / nilai_sekarang * 100;
        cout << "Compound Interest \t\t: " << "Rp. " << compound_interest << endl;
        cout << "Nilai Masa Depan / Future Value : " << "Rp. " << nilai_masdep << endl;
        cout << "Growth Rate        \t\t: " << growth_rate << " % " << endl;
        }  
        else if (tahun == 10){
        compound_interest = (nilai_sekarang * (A * A * A * A * A * A  * A * A * A *A)) - nilai_sekarang;
         nilai_masdep = nilai_sekarang + compound_interest;
         selisih = (nilai_masdep - nilai_sekarang);
         growth_rate = selisih / nilai_sekarang * 100;
        cout << "Compound Interest \t\t: " << "Rp. " << compound_interest << endl;
        cout << "Nilai Masa Depan / Future Value : " << "Rp. " << nilai_masdep << endl;
        cout << "Growth Rate        \t\t: " << growth_rate << " % " << endl;
        }
        else if (tahun == 15){
        compound_interest = (nilai_sekarang * (A * A * A * A * A * A  * A * A * A *A * A * A * A * A * A)) - nilai_sekarang;
         nilai_masdep = nilai_sekarang + compound_interest;
         selisih = (nilai_masdep - nilai_sekarang);
         growth_rate = selisih / nilai_sekarang * 100;
        cout << "Compound Interest \t\t: " << "Rp. " << compound_interest << endl;
        cout << "Nilai Masa Depan / Future Value : " << "Rp. " << nilai_masdep << endl;
        cout << "Growth Rate        \t\t: " << growth_rate << " % " << endl;
        } else {
            cout << "Data yang anda masukan belum tersedia saat ini" << endl;
        }
    
    cout << "--------------------------------------------------" << endl;
    cout << "\nIngin menghitung lagi<y> atau kembali ke menu <n> : ";
        cin >> pilih;
        if (pilih == 'y' || pilih == 'Y'){
            goto compoundinterest;
        } else if (pilih == 'n' || pilih == 'N'){
            goto menu;
        }
        break;
        
        case 4: //cash divident calculator - menu 4
        cashdivident :
        system ("cls");
        int divident,cekkode,nett_amount,jumlah;
        float tax,pajak;
        system ("cls");
        cout << "===Cash Divident Calculator===" << endl;
        hitung :
        cout << "Jumlah lot : ";
        cin >> tot_lot;
        cout << "Divident per Share : ";
        cin >> divident;
        cout << "Tax (%) : ";
        cin >> pajak;
    
        pajak = pajak/100;
        lembarshm= 100 * tot_lot;
        jumlah = lembarshm * divident;
        tax =  jumlah * pajak ;
        nett_amount = jumlah - tax;
        
        cout << "\n\n\n";
        cout << "--------------------------------------------------" << endl;
        cout << "Tax \t: " << "Rp. " << tax << endl;
        cout << "Nett Amount : " << "Rp. " << nett_amount << endl;
        cout << "--------------------------------------------------" << endl;

         cout << "\nIngin menghitung lagi<y> atau kembali ke menu <n> : ";
        cin >> pilih;
        if (pilih == 'y' || pilih == 'Y'){
            goto cashdivident;
        } else if (pilih == 'n' || pilih == 'N'){
            goto menu;
        }
      break;

        case 5:
      
        cout << "---EXIT---";
        break;

        default: //jika memasukan menu yang salah
        cout << "---Pilihan tidak valid--- " << endl;   
    
    }

}