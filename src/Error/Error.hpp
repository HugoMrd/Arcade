/*
** EPITECH PROJECT, 2023
** B-OOP-400-PAR-4-1-arcade-hugo.mouraud
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_
    #include <exception>
    #include <string>

namespace arcade {
    /**
    * @class Error
    * @brief Custom exception class used to handle errors in the arcade program
    */
    class Error : public std::exception {
        public:
            /**
            * @brief Default constructor for the Error class
            * @param msg Error message to display
            */
            Error(std::string msg = "") {this->_msg = msg;}
            /**
             * @brief Returns the error message associated with the exception
             * @return A const char pointer to the error message
             */
            const char *what() const noexcept override { return _msg.c_str();}
        private:
            std::string _msg;
    };
}

#endif /* !ERROR_HPP_ */
