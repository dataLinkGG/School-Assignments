#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Matrix {
private:
    int rows,cols;
    float** data;
public:
    Matrix() // default Constructor
    {
        rows = 0;
        cols = 0;
        data = NULL;
    }
    Matrix(int _rows, int _cols) // constructor with parameters
    {
        rows = _rows;
        cols = _cols;
        data = new float*[rows];
        for (int i = 0; i < rows; i++) {
                data[i] = new float[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = 0;
            }
        }
    }
    ~Matrix() // deallocate heap memory
    {
        if (data) {
            for ( int i = 0; i < rows; i++ ) {
                delete []data[i];
            }
        }
        delete []data;
    }
    void display_matrix() // display a simple matrix
    {
        for (int i = 0; i < rows; i++) {
            cout << endl << "|";
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << "\t";
            }
            cout << "|";
        }
        cout << endl;
    }
    void display_crossed_matrix() // display simple matrix, but crossed
    {
        for (int i = 0; i < rows; i++) {
            cout << endl << "|";
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << "\t";
            }
            cout << "| " << cross_a_row(i);
        }
        cout << endl << endl << " ";
        for (int j = 0; j < cols; j++) {
            cout << cross_a_col(j) << "\t";
        }
        cout << endl;
    }
    float cross_a_col(int the_col) // sum from vertical lines
    {
        float total = data[0][the_col];
        for (int i = 0; i < rows-1; i++) {
            total += data[i+1][the_col];
        }
        return total;
    }
    float cross_a_row(int the_row) // sum from horizontal lines
    {
        float total = data[the_row][0];
        for (int j = 0; j < cols-1; j++) {
            total += data[the_row][j+1];
        }
        return total;
    }
    friend class SalesInfo; // SalesInfo also matrix, so let's use class Matrix
};

class Slip {
private:
    int salesperson_id;
    int product_id;
    float total_dollar;
public:
    Slip()
    {
        salesperson_id = 0;
        product_id = 0;
        total_dollar = 0.00;
    }
    Slip(int _salesperson_id, int _product_id, float _total_dollar)
    {
        salesperson_id = _salesperson_id;
        product_id = _product_id;
        total_dollar = _total_dollar;
    }
    int get_salesperson_id() // optional
    {
        return salesperson_id;
    }
    int get_product_id() // optional
    {
        return product_id;
    }
    float get_total_dollar() // optional
    {
        return total_dollar;
    }
    void display_slip() // optional
    {
        cout << salesperson_id << " " << product_id << " ";
        display_money(total_dollar);
    }
    void display_money(float amount)
    {
        printf("R$ %0.2f\n",amount);
    }
};

class SalesInfo : public Matrix {
private:
    int n_salesperson;
    int n_products;
public:
    SalesInfo() : Matrix()
    {
        n_salesperson = 0;
        n_products = 0;
    }
    SalesInfo(int _n_products,int _n_salesperson): Matrix(_n_products,_n_salesperson)
    {
        n_salesperson = _n_salesperson;
        n_products = _n_products;
    }
    int gen_rdm_info(const char* file_path)
    {
        int rnd_product, rnd_salerperson, n_slips = 10;
        const int days_in_the_month = 30; // we can write a function later on
        const int max_slips_day = 4;
        float unit_price[] = {1.25 , 5.00 , 8.50 , 14.00}; // just to test my programm...
        //float LO = 1, HI = 50;
        float rtd;

        SalesInfo rnd(4,5);

        FILE *file = fopen(file_path,"w");

        if (file == NULL) {
            cout << "Program failed to open file." << file_path;
            return -1;
        }

        /* uncomment this if you want to use random values for unit_price
        for (int i = 0; i < n_products; i++) {
            unit_price[i] = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        }
        */

        n_slips = rand()%days_in_the_month*max_slips_day;
        fprintf(file,"%d\n",n_slips);
        for (int i = 1; i <= n_slips; i++) {
            rnd_product = rand()%n_products; // 0 to 3 in this particular assigment
            rnd_salerperson = rand()%n_salesperson; // 0 to 4
            rtd = rdm_total_dollar(unit_price[rnd_product]);
            fprintf(file,"%d %d %.2f\n",rnd_product,rnd_salerperson,rtd);
        }
        fclose(file);
        return n_slips;
    }
    void summarize_slips(const char* file_path) // summarize all the slips from a file
    {
        FILE *file = fopen(file_path,"r");
        int _product_id, _salesperson_id;
        float _total_dollar;
        int n_slips;
        if (file == NULL) {
            cout << "Wrong path to file." << file_path;
            return;
        }
        fscanf(file,"%d",&n_slips);
        for (int i = 1; i < n_slips; i++) {
            fscanf(file,"%d %d %f",&_product_id,&_salesperson_id,&_total_dollar);
            //cout << _product_id << " " << _salesperson_id << " " << _total_dollar << endl;
            this->data[_product_id][_salesperson_id] += _total_dollar;
        }

        fclose(file);
    }
    float rdm_total_dollar(float item_price) // get a random element for the matrix
    {
        return item_price*(rand()%10);

    }
};

int main()
{
    const char* file_path = "/home/thomas/Desktop/data.txt";
    int n_products = 4;
    int n_salesperson = 5;

    srand(time(NULL));

    SalesInfo sales(n_products,n_salesperson);

    sales.gen_rdm_info(file_path);
    sales.summarize_slips(file_path);
    sales.display_crossed_matrix();
    sales.display_matrix();

    return 0;
}
