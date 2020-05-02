[![Build Status](https://travis-ci.org/yasukei/junk_cpp.svg)](https://travis-ci.org/yasukei/junk_cpp)

## Reference
https://ja.cppreference.com/w/cpp/header

## TODO
- put test logs by tracis-ci to somewhere and make it visible

```
## �R���Z�v�g���C�u����
<concepts> (C++20�ȏ�)	��b�I�ȃ��C�u�����R���Z�v�g

## �R���[�`�����C�u����
<coroutine> (C++20�ȏ�)	�R���[�`���T�|�[�g���C�u����

## ���[�e�B���e�B���C�u����
<cstdlib>	�ėp���[�e�B���e�B: �v���O��������A���I�������m�ہA�����A�\�[�g�ƌ���
<csignal>	�V�O�i���Ǘ��̂��߂̊֐��ƃ}�N���萔
<csetjmp>	���s�R���e�L�X�g��ۑ� (����уW�����v) ����}�N�� (����ъ֐�)
<cstdarg>	�ϒ��������X�g�̏���
<typeinfo>	���s���^��񃆁[�e�B���e�B
<typeindex> (C++11�ȏ�)	std::type_index
<type_traits> (C++11�ȏ�)	�R���p�C�����^���
<functional>	�֐��I�u�W�F�N�g�A�֐��Ăяo���A�o�C���h����A�Q�ƃ��b�p�[
<utility>	�l�X�ȃ��[�e�B���e�B���i
<ctime>	C �X�^�C���̓��t�Ǝ��Ԃ̃��[�e�B���e�B
<chrono> (C++11�ȏ�)	C++ �̎��ԃ��[�e�B���e�B
<cstddef>	�W���I�ȃ}�N���� typedef
<initializer_list> (C++11�ȏ�)	std::initializer_list �N���X�e���v���[�g
<tuple> (C++11�ȏ�)	std::tuple �N���X�e���v���[�g
<any> (C++17�ȏ�)	std::any �N���X
<optional> (C++17�ȏ�)	std::optional �N���X�e���v���[�g
<variant> (C++17�ȏ�)	std::variant �N���X�e���v���[�g
<compare> (C++20�ȏ�)	�O����r���Z�q�T�|�[�g
<version> (C++20�ȏ�)	�����ˑ��̃��C�u���������������܂�
<source_location> (C++20�ȏ�)	�\�[�X�R�[�h�ʒu�����擾�����i���������܂�

## ���I�������Ǘ�
<new>	�ᐅ���������Ǘ����[�e�B���e�B
<memory>	�������������Ǘ����[�e�B���e�B
<scoped_allocator> (C++11�ȏ�)	�l�X�g���ꂽ�A���P�[�^�N���X
<memory_resource> (C++17�ȏ�)	�����A���P�[�^�ƃ��������\�[�X

## ���l�̌��E
<climits>	�����^�̌��E
<cfloat>	���������_�^�̌��E
<cstdint> (C++11�ȏ�)	�Œ�T�C�Y�̌^�Ƒ��̌^�̌��E
<cinttypes> (C++11�ȏ�)	�����}�N���Aintmax_t ����� uintmax_t �̐��w�ƕϊ�
<limits>	�Z�p�^�̓�����₢���킹��W�������ꂽ���@

## �G���[����
<exception>	��O�������[�e�B���e�B
<stdexcept>	�W���̗�O�I�u�W�F�N�g
<cassert>	�������[���Ɣ�r��������R���p�C�������}�N��
<system_error> (C++11�ȏ�)	�v���b�g�t�H�[���ˑ��̃G���[�R�[�h std::error_code �̒�`
<cerrno>	�Ō�̃G���[�ԍ���ێ�����}�N��
## �����񃉃C�u����
<cctype>	�����̎�ނ𔻒肷��֐�
<cwctype>	���C�h�����̎�ނ𔻒肷��֐�
<cstring>	�l�X�ȃi���[�����񏈗��֐�
<cwchar>	�l�X�ȃ��C�h����у}���`�o�C�g�����񏈗��֐�
<cuchar> (C++11�ȏ�)	C �X�^�C���� Unicode �����ϊ��֐�
<string>	std::basic_string �N���X�e���v���[�g
<string_view> (C++17�ȏ�)	std::basic_string_view �N���X�e���v���[�g
<charconv> (C++17�ȏ�)	std::to_chars ����� std::from_chars
<format> (C++20�ȏ�)	���������C�u���� (std::format �Ȃ�)

## �R���e�i���C�u����
<array> (C++11�ȏ�)	std::array �R���e�i
<vector>	std::vector �R���e�i
<deque>	std::deque �R���e�i
<list>	std::list �R���e�i
<forward_list> (C++11�ȏ�)	std::forward_list �R���e�i
<set>	std::set ����� std::multiset �A�z�R���e�i
<map>	std::map ����� std::multimap �A�z�R���e�i
<unordered_set> (C++11�ȏ�)	std::unordered_set ����� std::unordered_multiset �񏇏��A�z�R���e�i
<unordered_map> (C++11�ȏ�)	std::unordered_map ����� std::unordered_multimap �񏇏��A�z�R���e�i
<stack>	std::stack �R���e�i�A�_�v�^
<queue>	std::queue ����� std::priority_queue �R���e�i�A�_�v�^
<span> (C++20�ȏ�)	std::span �r���[

## �C�e���[�^���C�u����
<iterator>	�͈͂̃C�e���[�^

## �͈̓��C�u����
<ranges> (C++20�ȏ�)	�͈̓A�N�Z�X�A�v���~�e�B�u�A�v���A���[�e�B���e�B����уA�_�v�^

## �A���S���Y�����C�u����
<algorithm>	�͈͂ɑ΂��鑀����s���A���S���Y��
<execution> (C++17�ȏ�)	����ł̃A���S���Y���̂��߂̒�`�ς݂̎��s�|���V�[

## ���l���Z���C�u����
<cmath>	��ʓI�Ȑ��w�֐�
<complex>	���f���^
<valarray>	�l�̔z���\���A���삷�邽�߂̃N���X
<random> (C++11�ȏ�)	������������ѕ��z
<numeric>	�R���e�i���̒l�ɑ΂��鐔�l���Z
<ratio> (C++11�ȏ�)	�R���p�C�����L�����Z�p
<cfenv> (C++11�ȏ�)	���������_���ɃA�N�Z�X����֐�
<bit> (C++20�ȏ�)	�r�b�g����֐�
<numbers> (C++20�ȏ�)	���w�萔

## ���o�̓��C�u����
<iosfwd>	���o�̓��C�u�����̂��ׂẴN���X�̑O���錾
<ios>	std::ios_base �N���X�Astd::basic_ios �N���X�e���v���[�g�Ƃ������� typedef
<istream>	std::basic_istream �N���X�e���v���[�g�Ƃ������� typedef
<ostream>	std::basic_ostream, std::basic_iostream �N���X�e���v���[�g�Ƃ������� typedef
<iostream>	�������̕W���X�g���[���I�u�W�F�N�g
<fstream>	std::basic_fstream, std::basic_ifstream, std::basic_ofstream �N���X�e���v���[�g�Ƃ������� typedef
<sstream>	std::basic_stringstream, std::basic_istringstream, std::basic_ostringstream �N���X�e���v���[�g�Ƃ������� typedef
<syncstream> (C++20�ȏ�)	std::basic_osyncstream, std::basic_syncbuf �� typedef
<strstream> (C++98�Ŕ񐄏�)	std::strstream, std::istrstream, std::ostrstream
<iomanip>	���o�͂̏����𐧌䂷��w���p�[�֐�
<streambuf>	std::basic_streambuf �N���X�e���v���[�g
<cstdio>	C �X�^�C���̓��o�͊֐�

## ���[�J���C�[�[�V�������C�u����
<locale>	���[�J���C�[�[�V�������[�e�B���e�B
<clocale>	C �̃��[�J���C�[�[�V�������[�e�B���e�B
<codecvt> (C++11�ȏ�) (C++17�Ŕ񐄏�)	Unicode �ϊ��@�\

## ���K�\�����C�u����
<regex> (C++11�ȏ�)	���K�\���������T�|�[�g����N���X�A�A���S���Y������уC�e���[�^

## �A�g�~�b�N���색�C�u����
<atomic> (C++11�ȏ�)	�A�g�~�b�N���색�C�u����

## �X���b�h�T�|�[�g���C�u����
<stop_token> (C++20�ȏ�)	std::jthread �̂��߂̃X�g�b�v�g�[�N��
<shared_mutex> (C++14�ȏ�)	���L�\�ȑ��ݔr���v���~�e�B�u
<condition_variable> (C++11�ȏ�)	�X���b�h�̑ҋ@���
<semaphore> (C++20�ȏ�)	�Z�}�t�H
<latch> (C++20�ȏ�)	���b�`
<barrier> (C++20�ȏ�)	�o���A

##�t�@�C���V�X�e�����C�u����
<filesystem> (C++17�ȏ�)	std::path �N���X�ƃT�|�[�g�֐�
```
