/*
 * config.h - convenient function for read config
 */

#ifndef CONFIG_H
#define CONFIG_H
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

class Config {
    using property = boost::property_tree::ptree;
    using propertyPtr = std::shared_ptr<property>;
    using string = std::string;
    
    private:
        // class Config works as singleton mode
        static propertyPtr& _property() {
            static propertyPtr __property;
            return __property;
        }

    public:
        static bool parse(const string confPath) {
            try {
                propertyPtr tmpProperty(new property);
                boost::property_tree::ini_parser::read_ini(confPath, *tmpProperty);
                _property().swap(tmpProperty);
                return true;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return false;
            }
        }

        static propertyPtr getProperty() {
            return _property();
        }

        template <typename T>
        static T get(string key) {
            return _property()->get<T>(key);
        }

        template <typename T>
        static void set(string key, T value) {
            _property()->put<T>(key, value);
        }

        // dump the current configuration to output stream.
        static void dump(std::ostream &stream = std::cout) {
            boost::property_tree::ini_parser::write_ini(std::cout, *_property());
        }
};
#endif