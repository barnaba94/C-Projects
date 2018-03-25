#pragma once

int  ReadData(LottoPlayer*** pAllDraws, const char* sfileName);
void FreeMem(LottoPlayer** pTab, int nDrawsNo);
int  SetSex(LottoPlayer* p, char c);
int  SetDate(LottoPlayer* p, int d, int m, int y);
