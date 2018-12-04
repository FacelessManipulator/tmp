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
        static propertyPtr _property() {
            static propertyPtr __property;
            return __property;
        }

    public:
        static void parse(const string confPath) {
            _property().reset(new property);
            boost::property_tree::ini_parser::read_ini("config.ini", *_property());
        }

        static propertyPtr getProperty() {
            return _property();
        }

        template <typename T>
        static T get(string key) {
            return _property->get<T>(key);
        }

        template <typename T>
        static void set(string key, T value) {
            _property->add<T>(key, value);
        }

        static void dump() {
            boost::property_tree::ini_parser::write_ini(std::cout, *_property());
        }
};
#endif