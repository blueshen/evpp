#pragma once

#include <stdint.h>

#include <memcached/protocol_binary.h>

#include "evpp/buffer.h"
#include "evpp/tcp_conn.h"
#include "evpp/timestamp.h"

#include "command.h"

namespace evmc {

class MemcacheClient;

class BinaryCodec {
 public:
  explicit BinaryCodec(MemcacheClient *memc_client) : memc_client_(memc_client) {}

  void OnCodecMessage(const evpp::TCPConnPtr &conn,
                      evpp::Buffer *buf);

 private:
  // noncopyable
  BinaryCodec(const BinaryCodec &);
  void DecodePrefixGetPacket(const protocol_binary_response_header &resp,
                             evpp::Buffer *buf, std::string &key, CommandPtr &cmd);
  const BinaryCodec &operator=(const BinaryCodec &);

  void OnResponsePacket(const protocol_binary_response_header &resp,
                        evpp::Buffer *buf);
 private:
  // TODO : ��ʹ������ָ�룬Ҫ����ѭ������. client�Ļص���������codec
  MemcacheClient *memc_client_;
};

}

