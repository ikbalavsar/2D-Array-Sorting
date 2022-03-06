#include <iostream>
#include <fstream>
using namespace std;

void get_store_data(int array[100][100], int row, int column);
void read_array(int array[100][100], int row, int column);
void print_array(int array[100][100], int row, int column);
void ascending_descending(int array[100][100], int row, int column);

int main() {
    int n, m;
    cout << "Please enter the row value: ";
    cin >> n;
    cout << "Please enter the column value: ";
    cin >>m ;
    int array[100][100];

    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            cout<< "Enter the value of index "<< i<<" "<< j<<": ";
            cin >> array[i][j];
        }
    }
    get_store_data(array, n, m);
    read_array(array,n,m);
    cout <<"\n\n";
    ascending_descending(array,n,m);
    cout<<"\n\n";
    print_array(array, n,m);
    return 0;
}

void get_store_data(int array[100][100], int row, int column){

    string line;
    ofstream myFile;
    myFile.open("data_test.txt");

    for(int i = 0; i< row; i++){
        for(int j = 0; j < column ; j++){
            myFile << array[i][j]<< " ";

        }
        myFile << "\n";
    }
    myFile.close();
}

void read_array(int array[100][100],int row, int column){
    string line;
    ifstream file;
    file.open("data_test.txt");

    if(file.is_open()){
        for(int i = 0 ; i< row;i++ ){
            for(int j = 0 ; j < column; j++){
                file >> array[i][j];
                cout << array[i][j]<< " ";
            }
        }
    }
    file.close();
}

void ascending_descending(int array[100][100], int row, int column){
    int temp_array[100*100];
    int k = 0;
    int size;

    for(int i = 0; i< row;i++) {
        for (int j = 0; j < column; j++) {
            temp_array[k++] = array[i][j];
        }
    }

    size = k ;

    for(int i =0 ; i< size ; i++){
        for(int j = 0 ; j< size -i-1; j++){
            if(temp_array[j] > temp_array[j+1]){
                int temp = temp_array[j];
                temp_array[j] = temp_array[j+1];
                temp_array[j+1] = temp;
            }
        }
    }

    k = 0;
    for( int i = 0 ; i < row/2; i++){
        for(int j = 0 ; j < column ; j++){
            array[i][j] = temp_array[k++];
        }
    }

    for(int i =0; i < size ; i++){
        for(int j = 0; j < size -i-1; j++){
            if(temp_array[j] < temp_array[j+1]){
                int temp = temp_array[j];
                temp_array[j] = temp_array[j+1];
                temp_array[j+1] = temp;
            }
        }
    }
    k= 0;
    for(int i = row/2; i < row; i++){
        for( int j = 0; j < column ; j++){
            array[i][j] = temp_array[k++];
        }
    }
}


void print_array(int array[100][100], int row, int column){
    for(int i = 0 ; i < row; i++){
        for (int j = 0 ; j< column ; j++){
            cout << array[i][j] << " ";
        }
        cout<<"\n";
    }
}

