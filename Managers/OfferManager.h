#ifndef STORE_OFFERMANAGER_H
#define STORE_OFFERMANAGER_H

#include <vector>
#include "../Store/ProductOffer.h"

class OfferManager {
private:
    ProductOffer m_offer;
public:
    ProductOffer getOffer(){return m_offer;};

    void setOffer(const ProductOffer &offer){m_offer = offer;}
};


#endif
