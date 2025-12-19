#ifndef ONYX_H
#define ONYX_H
#include <ratio>
#include <concepts>
#include <type_traits>
namespace onyx {
    struct FrequencyTag {};
    struct AmplitudeTag {};
    struct TimeTag {};
//Unit Template
    template <typename D, typename R = std::ratio<1>>
    struct Quantity {
        using Dimension = D;
        using Ratio = R;
        double value;
        explicit constexpr Quantity(double val) : value(val) {}
        constexpr Quantity operator+(const Quantity& other) const {
            return Quantity(value + other.value);
        }
        constexpr Quantity operator-(const Quantity& other) const {
            return Quantity(value - other.value);
        }
    }; 
    using Hz  = Quantity<FrequencyTag, std::ratio<1>>;
    using kHz = Quantity<FrequencyTag, std::kilo>;
    using db  = Quantity<AmplitudeTag, std::ratio<1>>;
    using ms  = Quantity<TimeTag, std::milli>;
    using sec = Quantity<TimeTag, std::ratio<1>>;
    namespace literals {
        constexpr Hz operator"" _hz(long double val) { return Hz(static_cast<double>(val)); }
        constexpr Hz operator"" _hz(unsigned long long val) { return Hz(static_cast<double>(val)); }
        constexpr kHz operator"" _khz(long double val) { return kHz(static_cast<double>(val)); }
        constexpr db operator"" _db(long double val) { return db(static_cast<double>(val)); } 
        constexpr ms operator"" _ms(long double val) { return ms(static_cast<double>(val)); }
        constexpr sec operator"" _sec(long double val) { return sec(static_cast<double>(val)); }
    }
    template <typename To, typename From>
    constexpr To convert(From unit) {
        static_assert(std::is_same_v<typename To::Dimension, typename From::Dimension>, 
                      "ONYX ERROR: Cannot convert between different dimensions!");        
// Calculate factor: (FromRatio / ToRatio)
        double factor = static_cast<double>(From::Ratio::num * To::Ratio::den) / 
                        static_cast<double>(From::Ratio::den * To::Ratio::num);
        
        return To(unit.value * factor); 
    }
}
#endif