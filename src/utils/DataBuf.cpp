#include "DataBuf.h"

bool DataBuf::isNull() const {
    return m_buf == nullptr;
}

uint8_t* DataBuf::getData() {
    return m_buf;
}

size_t DataBuf::getSize() {
    return m_size;
}

std::string DataBuf::toString() {
    return std::string((char *)m_buf);
}

void DataBuf::fastSet(uint8_t* buf, size_t size) {
    m_buf = buf;
    m_size = size;
}
