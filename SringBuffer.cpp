//Author: jadecubes by MIT Licence

#include "SringBuffer.h"
//distance between wi to buttom
unsigned int RingWBDistance(SRingBuffer *RingBuffer){return (RingBuffer->MaxLen - RingBuffer->wi);}

//Avallible write space
unsigned int RingAvailableSpace(SRingBuffer *RingBuffer){return (RingBuffer->MaxLen - RingBuffer->TotalLen);}

//distance between ri to buttom
unsigned int RingRBDistance(SRingBuffer *RingBuffer){return (RingBuffer->MaxLen - RingBuffer->ri);}

//check wi is over boundery or not
void RingCheckWi(SRingBuffer *RingBuffer){if(RingBuffer->wi>=RingBuffer->MaxLen) RingBuffer->wi-=RingBuffer->MaxLen;}

//check ri is over boundery or not
void RingCheckRi(SRingBuffer *RingBuffer){if(RingBuffer->ri>=RingBuffer->MaxLen) RingBuffer->ri-=RingBuffer->MaxLen;}

//Ring initial function
void RingInit(SRingBuffer *RingBuffer,char* buff,int max_len)
{RingBuffer->ri=0;RingBuffer->wi=0;RingBuffer->TotalLen=0;RingBuffer->buf=buff;RingBuffer->MaxLen=max_len;}

//Increase ri
void RingIncRi(SRingBuffer *RingBuffer,int len)
{RingBuffer->ri+=len;RingCheckRi(RingBuffer); RingBuffer->TotalLen-=len;}

//Increase wi
void RingIncWi(SRingBuffer *RingBuffer,int len)
{RingBuffer->wi+=len;RingCheckWi(RingBuffer);RingBuffer->TotalLen+=len;}

