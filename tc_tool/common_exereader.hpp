#ifndef LIERO_COMMON_EXEREADER_HPP
#define LIERO_COMMON_EXEREADER_HPP

#include "common.hpp"

struct ReaderFile;

void loadFromExe(Common& common, ReaderFile& exe, ReaderFile& gfx, ReaderFile& snd);
void loadSfx(std::vector<sfx_sound*>& sounds, ReaderFile& snd);

#endif // LIERO_COMMON_EXEREADER_HPP
