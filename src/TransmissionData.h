#ifndef __dx_TRANSMISSIONDATA_H__
#define __dx_TRANSMISSIONDATA_H__

#include <memory>

class DeliveryNotifier;
class TransmissionData {
public:
    virtual void onDeliveryFail(DeliveryNotifier*) const = 0;
    virtual void onDeliverySucc(DeliveryNotifier*) const = 0;
};

typedef std::shared_ptr<TransmissionData> TransmissionDataPtr;

#endif /* __dx_TRANSMISSIONDATA_H__ */
