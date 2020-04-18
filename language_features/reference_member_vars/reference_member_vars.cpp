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
    ToiletPaperInterface() = delete;

    ToiletPaperInterface(ToiletPaperStock& tp_stock) : _current_tp_stock(tp_stock)
    {}

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
    ToiletPaperInterface tp_interface1(tp_stock);
    std::cout << "---- Interface 1 ----" << std::endl;
    printTPStock(tp_interface1);

    // Declare another interface to view tp stock
    ToiletPaperInterface tp_interface2(tp_stock);
    std::cout << "---- Interface 2 ----" << std::endl;
    printTPStock(tp_interface2);

    //ToiletPaperInterface tp_interface3; // doesn't work - even without deleting the default constructor

    std::cout << std::endl << "New toilet paper shipment arrived in store!" << std::endl << std::endl;

    tp_stock._aisle_name = "Aisle 6";
    tp_stock._number_of_tp_rolls = 200;

    // Show updated values via both interfaces
    std::cout << "---- Interface 1 ----" << std::endl;
    printTPStock(tp_interface1);
    std::cout << "---- Interface 2 ----" << std::endl;
    printTPStock(tp_interface2);    

    return 0;
}