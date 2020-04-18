#include <string>
#include <iostream>

struct ToiletPaperStock
{
    std::string _aisle_name;
    int         _number_of_tp_rolls;
};

class ToiletPaperInterface
{
public:
    // ToiletPaperInterface(ToiletPaperStock& tp_stock) : _current_tp_stock(tp_stock)
    // {}

    const std::string& getAisleName() const
    {
        return _current_tp_stock._aisle_name;
    }

    int getNumberOfToiletPaperRolls() const
    {
        return _current_tp_stock._number_of_tp_rolls;
    }
private:
    ToiletPaperStock& _current_tp_stock;
};

void printTPStock(const ToiletPaperInterface& tp_iface)
{
    std::cout << "Aisle name tp roll location: " << tp_iface.getAisleName() << std::endl
              << "Current number of toilet paper rolls: " << tp_iface.getNumberOfToiletPaperRolls() << std::endl;
}

int main()
{
    // Declare a toilet paper stock
    ToiletPaperStock tp_stock;
    tp_stock._aisle_name = "none";
    tp_stock._number_of_tp_rolls = 0;
    
    // Declare an interface to view tp stock
    ToiletPaperInterface tp_interface();
    printTPStock(tp_interface);

    return 0;
}