#include <iostream>
#include <vector>
#include <algorithm>

// vector of shorts alias
typedef std::vector<short> wektor;

// function for finding the mid-weight vector element
wektor::size_type srodek(wektor& vec) {

    // function internal callable class for for_each algorithm
    class sumator {
        public:
            sumator(): _sum(0) {
                std::cout << __PRETTY_FUNCTION__ << "#" << __LINE__ << std::endl;
            }
            // callable operator
            void operator() (const wektor::value_type& i) {
                std::cout << __PRETTY_FUNCTION__ << "#" << __LINE__  << std::endl;
                _sum += i;
            }
            // getter
            wektor::value_type half() const {
                std::cout << __PRETTY_FUNCTION__ << "#" << __LINE__ << std::endl;
                return _sum / 2;
            }

        private:
            wektor::value_type _sum;
    };

    std::cout << __PRETTY_FUNCTION__ << "#" << __LINE__ << std::endl;
    sumator sum;
    /*sumator sum = */std::for_each(vec.begin(), vec.end(), sum); //sum.operator() (short a);
    wektor::value_type half = 0;
    for(wektor::iterator it = vec.begin(); it != vec.end(); ++it) {
        half += *it;
        if(half >= sum.half()) {
            return it - vec.begin();
        }
    }
    return vec.size();
}

int main(int argc, char* argv[]) {
    std::cout << __PRETTY_FUNCTION__ << "#" << __LINE__ << std::endl;

    wektor vec = {100, 3, 5, 7, 3, 10, 123, 124};
    wektor::size_type mid = srodek(vec);
    std::cout << "polowa: [" << mid << "] = " << vec[mid] << std::endl;
    return 0;
}


//roznice miedzy kontenerami sekewncejnymi (wektor, lsita, que)-bardzo latwo cos wlozyc, ale szukanie 
// ma zlozonosc liniowo, zeby cos znalezc trzeba przejechac po wartosciach 
// a asocjacyjnymi (set, multiset, map, multimap) - trudniej sie do nich wklada np. set jest na b-drzewie (bit) 
//ale zlozonosc wyszukiwania jest znacznei szybko (log n) (logarytmiczne szukanie)
//
