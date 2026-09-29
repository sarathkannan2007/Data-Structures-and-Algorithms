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
            table[index] = key;
        }

        void Display()
        {
            for (int i =0; i < table_size; i++)
            {
                cout << i << " " << table[i] << endl;
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
