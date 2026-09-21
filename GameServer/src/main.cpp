namespace ch01::prime_number { int ExecMain(); }
namespace ch01::prime_number_multithreaded { int ExecMain(); }

int main()
{
    ch01::prime_number::ExecMain();
    ch01::prime_number_multithreaded::ExecMain();
}