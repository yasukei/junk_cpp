cmake_minimum_required(VERSION 3.2)
project(std)

include(CTest)
enable_testing()

## �R���Z�v�g���C�u����

## �R���[�`�����C�u����

## ���[�e�B���e�B���C�u����
### <bitset>	std::bitset �N���X�e���v���[�g
add_subdirectory(bitset)

### <tuple> (C++11�ȏ�)	std::tuple �N���X�e���v���[�g
add_subdirectory(tuple)

### <ctime>	C �X�^�C���̓��t�Ǝ��Ԃ̃��[�e�B���e�B
add_subdirectory(ctime)

### <chrono> (C++11�ȏ�)	C++ �̎��ԃ��[�e�B���e�B
add_subdirectory(chrono)

### <typeinfo>	���s���^��񃆁[�e�B���e�B
add_subdirectory(typeinfo)

## ���I�������Ǘ�

## ���l�̌��E

## �G���[����

## �����񃉃C�u����

## �R���e�i���C�u����
### <array> (C++11�ȏ�)	std::array �R���e�i
add_subdirectory(array)

### <vector>	std::vector �R���e�i
add_subdirectory(vector)

### <list>	std::list �R���e�i
add_subdirectory(list)

### <forward_list> (C++11�ȏ�)	std::forward_list �R���e�i
add_subdirectory(forward_list)

### <deque>	std::deque �R���e�i
add_subdirectory(deque)

### <queue>	std::queue ����� std::priority_queue �R���e�i�A�_�v�^
add_subdirectory(queue)

### <stack>	std::stack �R���e�i�A�_�v�^
add_subdirectory(stack)

### <map>	std::map ����� std::multimap �A�z�R���e�i
add_subdirectory(map)

### <set>	std::set ����� std::multiset �A�z�R���e�i
add_subdirectory(set)

### <unordered_map> (C++11�ȏ�)	std::unordered_map ����� std::unordered_multimap �񏇏��A�z�R���e�i
add_subdirectory(unordered_map)

### <unordered_set> (C++11�ȏ�)	std::unordered_set ����� std::unordered_multiset �񏇏��A�z�R���e�i
add_subdirectory(unordered_set)

## �C�e���[�^���C�u����

## �͈̓��C�u����

## �A���S���Y�����C�u����
### <algorithm>	�͈͂ɑ΂��鑀����s���A���S���Y��
add_subdirectory(algorithm)

## ���l���Z���C�u����

## ���o�̓��C�u����

## ���[�J���C�[�[�V�������C�u����

## ���K�\�����C�u����

## �A�g�~�b�N���색�C�u����

## �X���b�h�T�|�[�g���C�u����
### <thread> (C++11�ȏ�)	std::thread �N���X�ƃT�|�[�g�֐�
add_subdirectory(thread)

### <mutex> (C++11�ȏ�)	���ݔr���v���~�e�B�u
add_subdirectory(mutex)

### <future> (C++11�ȏ�)	�񓯊��v�Z�̂��߂̃v���~�e�B�u
add_subdirectory(future)