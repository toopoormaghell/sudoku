#ifndef CRTP_IMPL_H
#define CRTP_IMPL_H

#ifndef CRTP_H
#error "This header is meant to be included by crtp.h only"
#endif

//------------------------------------------------------------------------------
T& underlying()
{
    return static_cast<T&>(*this);
}

//------------------------------------------------------------------------------
T const& underlying() const
{
    return static_cast<T const&>(*this);
}

#endif // CRTP_IMPL_H
