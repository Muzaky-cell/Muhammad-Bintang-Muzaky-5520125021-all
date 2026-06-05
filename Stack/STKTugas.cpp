#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
  stack<string> undoStack;
  string teksBaru;
  int pilihan;
    
	undoStack.push("");
      do{
       cout << "\n===== TEXT EDITOR =====" << endl;
       cout << "1. Ketik Teks" << endl;
       cout << "2. Undo" << endl;
       cout << "3. Tampilkan Dokumen" << endl;
       cout << "4. Keluar" << endl;
       cout << "Pilih: ";
       cin >> pilihan;
       cin.ignore();

    switch (pilihan){
      case 1:
        cout << "Masukkan teks: ";
        getline(cin, teksBaru);
    {
        string dokumen = undoStack.top();
        dokumen += teksBaru + "\n";
        undoStack.push(dokumen);
        
		}
        cout << "Teks berhasil ditambahkan!" << endl;
        break;

      case 2:
        if (undoStack.size() > 1) {
           undoStack.pop();
           cout << "Undo berhasil!" << endl;
           }else{
             cout << "Tidak ada data untuk di-undo!" << endl;
            }
            break;

      case 3:
        cout << "\n===== ISI DOKUMEN =====" << endl;
         if (undoStack.top().empty()) {
            cout << "Dokumen masih kosong." << endl;
            }else{
              cout << undoStack.top();
            }
            break;

      case 4:
        cout << "Program selesai." << endl;
        break;
          default:
            cout << "Pilihan tidak valid!" << endl;
        }

}while(pilihan != 4);

  return 0;
}

