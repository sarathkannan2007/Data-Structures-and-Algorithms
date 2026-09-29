#include <iostream>
using namespace std;
int table_size = 10;
class HASH
{
    private:
        int table[10];
    
    public :
        HASH()
        {
            for (int i = 0; i < table_size; i++)
            {
                table[i] = -1;
            }
        }
        int hashFunction(int key)
        {
            return key%10;
        }
        void insert(int key)
        {
            int index = hashFunction(key);
            int i = 0;
             
            while( table[index + i] % 10 != -1)
            {
                i++;
            }
            table[(index+i) % 10] = key;
        }

        void Display()
        {
            for (int i =0; i < table_size; i++)
            {
                cout << i << " " << table[i] << endl;
            }
        }

        void search(int search_value)
        {
            int search_key = hashFunction(search_value);
            for (int i = 0; i < table_size; i++)
            {
                int current = (search_value+1)%10;
                if(table[current] == search_value)
                {
                    cout << "Found : " << table[current] << endl;
                    return;
                }
                if (table[current] == -1)
                {
                    return;
                }
            }
        }

};
int main()
{
    HASH h;
    for (int i = 0; i < table_size; i++)
    {
        cout << "Enter the value to insert into Hash Table : ";
        int val;
        cin >> val;
        h.insert(val);
    }

    h.Display();
    return 0;
}
