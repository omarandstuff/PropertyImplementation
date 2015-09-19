#pragma once

template <typename TClass, typename TProperty>
class Property
{
public:
	Property();
	void syntetize(TClass* p_class, TProperty(TClass::*p_fp_get)(void), void (TClass::*p_fp_set)(TProperty));

	// -------------------------------------------- //
	// -------------- Getter / Setter ------------- //
	// -------------------------------------------- //
public:
	inline operator TProperty(void);
	inline TProperty operator=(TProperty value);
	inline TProperty operator+(TProperty value);
	inline TProperty operator-(TProperty value);
	inline TProperty operator*(TProperty value);
	inline TProperty operator/(TProperty value);
	inline TProperty operator+=(TProperty value);
	inline TProperty operator-=(TProperty value);
	inline TProperty operator*=(TProperty value);
	inline TProperty operator/=(TProperty value);
	inline TProperty operator<(TProperty value);
	inline TProperty operator>(TProperty value);
	inline TProperty operator==(TProperty value);
	inline TProperty operator!=(TProperty value);

private:
	inline TProperty getter(void);
	inline void setter(TProperty value);

	// -------------------------------------------- //
	// -------------- Private Members ------------- //
	// -------------------------------------------- //
private:
	void (TClass::*m_setter)(TProperty value);
	TProperty(TClass::*m_getter)();
	TClass * m_class;
};

// ------------------------------------------------------------------------------ //
// ------------------------------- Initialization ------------------------------- //
// ------------------------------------------------------------------------------ //

template <typename TClass, typename TProperty>
Property<TClass, TProperty>::Property()
{
	m_class = 0;
	m_setter = 0;
	m_getter = 0;
}

template <typename TClass, typename TProperty>
void Property<TClass, TProperty>::syntetize(TClass* p_class, TProperty(TClass::*p_fp_get)(void), void (TClass::*p_fp_set)(TProperty))
{
	m_class = p_class;
	m_setter = p_fp_set;
	m_getter = p_fp_get;
}

// ------------------------------------------------------------------------------ //
// --------------------------------- Operattors --------------------------------- //
// ------------------------------------------------------------------------------ //

template <typename TClass, typename TProperty>
Property<TClass, TProperty>::operator TProperty(void)
{
	return this->getter();
}

template <typename TClass, typename TProperty>
TProperty Property<TClass, TProperty>::operator=(TProperty value)
{
	this->setter(value);
	return *this;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator+(TProperty value)
{
	return this->getter() + value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator-(TProperty value)
{
	return this->getter() - value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator*(TProperty value)
{
	return this->getter() * value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator/(TProperty value)
{
	return this->getter() / value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator+=(TProperty value)
{
	return this->getter() += value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator-=(TProperty value)
{
	return this->getter() -= value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator*=(TProperty value)
{
	return this->getter() *= value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator/=(TProperty value)
{
	return this->getter() /= value;
}
template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator<(TProperty value)
{
	return this->getter() < value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator>(TProperty value)
{
	return this->getter() > value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator==(TProperty value)
{
	return this->getter() == value;
}

template <typename TClass, typename TProperty>
inline TProperty Property<TClass, TProperty>::operator!=(TProperty value)
{
	return this->getter() != value;
}

// ------------------------------------------------------------------------------ //
// ------------------------------- Setter / Getter ------------------------------ //
// ------------------------------------------------------------------------------ //

template <typename TClass, typename TProperty>
TProperty Property<TClass, TProperty>::getter(void)
{
	return (m_class->*m_getter)();
}

template <typename TClass, typename TProperty>
void Property<TClass, TProperty>::setter(TProperty value)
{
	(m_class->*m_setter)(value);
}
