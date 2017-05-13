#ifndef __DX_DATABUF_H__
#define __DX_DATABUF_H__

#include <cstdint>
#include <cstddef>
#include <string>

class DataBuf
{
public:
    DataBuf() {}
    bool isNull() const;
    uint8_t *getData();
    size_t getSize();
    std::string toString();
    void fastSet(uint8_t* buf, size_t size);
private:
    uint8_t* m_buf = nullptr;
    size_t m_size = 0;
};

#endif // __DX_DATABUF_H__
