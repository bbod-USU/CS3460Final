//
// Created by Brady Bodily on 12/11/19.
//
#pragma once
#include <iostream>
namespace usu
{
    template <typename T>
    class unique_ptr{
      public:

        ///
        ///Constructors
        ///
        unique_ptr():_data(nullptr){};
        unique_ptr(T item):_data(item){};
        unique_ptr(T *item){_data = item;};
        unique_ptr(unique_ptr&& item): _data(item._data){item._data = nullptr;}


        ///
        ///Destructor
        ///
        ~unique_ptr(){delete _data;}


        ///
        ///Operator Overloads
        ///
        T operator*(){return *_data;};
        T* operator->(){return _data;};
        bool operator == (const unique_ptr &rhs);
        bool operator != (const unique_ptr &rhs);


        ///
        ///CopyAssignable, MoveAssignable
        ///
        unique_ptr operator =  (unique_ptr &&rhs) noexcept {
            if (rhs._data == _data)
                return this->_data;
            auto tmp = _data;
            _data = rhs._data;
            rhs._data = tmp;
            return this->_data;
        };

        ///
        ///Functions
        ///
        T* get();
        T* release();

      private:
        T* _data;
    };


    /// == Operator Overload
    /// \tparam T
    /// \param rhs
    /// \return bool
    template <typename T>
    bool unique_ptr<T>::operator == (const unique_ptr &rhs){
        if(_data == rhs._data)
            return true;
        return false;
    }


    /// != Operator Overload
    /// \tparam T
    /// \param rhs
    /// \return bool
    template <typename T>
    bool unique_ptr<T>::operator != (const unique_ptr &rhs)
    {
        if (_data != rhs._data)
            return true;
        return false;
    }

    /// Gets Data Maintains Pointer
    /// \tparam T
    /// \return the data
    template <typename T>
    T* unique_ptr<T>::get() {
        return _data;
    }

    /// Releases the pointer
    /// \tparam T
    /// \return the data
    template <typename T>
    T* unique_ptr<T>::release() {
        auto returnValue = _data;
        _data = nullptr;
        return returnValue;
    }




    template <typename T, typename... Args>
    unique_ptr<T> make_unique(Args&&... args)
    {
        return unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

}

//HW7_UNIQUE_PTR_HPP
