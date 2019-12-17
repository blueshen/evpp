#pragma once

#ifdef _DEBUG
#ifndef H_INTERNAL_STATS
#define H_INTERNAL_STATS
#endif
#endif

#include <atomic>
#include "evpp/duration.h"

namespace evpp {
namespace http {
namespace stats {

// ������ʱ����Ӿ���һ��������Ӧ�ò�����ķѵĴ���ʱ��
struct Time {
  Duration dispatched_time; // �ӽ��յ�һ������ʼ��ʱ���������󱻵��ȵ������߳̿�ʼִ�У�֮������ĵ�ʱ��
  Duration execute_time; // �������ڹ����߳���ִ�й��̺ķѵ�ʱ��
  Duration response_time; // �������ڹ����߳�ִ�����ʱ��ʼ��ʱ������������ȵ������߳���ɷ��͹���Ϊֹ��֮�����ĵ�ʱ��
};

struct Count {
  std::atomic<uint64_t> recv; // ���յ����������
  std::atomic<uint64_t> dispatched; // �ַ��������߳��е��������
  std::atomic<uint64_t> responsed; // ���ͻ��˻�Ӧ���������
  std::atomic<uint64_t> failed; // ����ʧ�ܵ��������
  std::atomic<uint64_t> slow; // ���������������ʱ�䳬��һ������ֵ��
};
}
}
}