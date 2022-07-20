/*
 * main.c
 *
 *  Created on: 2016年8月20日
 *      Author: hsp
 *  本文件实现SD写入一段字符串，然后从其中读出并打印到串口。
 *
 */

#include <string.h>
#include "platform.h"
//#include "xparameters.h"

#include "xil_printf.h"
#include "ff.h"
//#include "xdevcfg.h"

static FATFS fatfs;

int SD_Init()
{
    FRESULT rc;

    rc = f_mount(&fatfs,"",0);
    if(rc)
    {
        xil_printf("ERROR : f_mount returned %d\r\n",rc);
        return 0;
    }
    return 1;
}

int SD_Transfer_read(char *FileName,u32 DestinationAddress,u32 ByteLength)
{
    FIL fil;
    FRESULT rc;
    UINT br;

    rc = f_open(&fil,FileName,FA_READ);
    if(rc)
    {
        xil_printf("ERROR : f_open returned %d\r\n",rc);
        return 0;
    }
    rc = f_lseek(&fil, 0);
    if(rc)
    {
        xil_printf("ERROR : f_lseek returned %d\r\n",rc);
        return 0;
    }
    rc = f_read(&fil, (void*)DestinationAddress,ByteLength,&br);
    if(rc)
    {
        xil_printf("ERROR : f_read returned %d\r\n",rc);
        return 0;
    }
    rc = f_close(&fil);
    if(rc)
    {
        xil_printf(" ERROR : f_close returned %d\r\n", rc);
        return 0;
    }
    return 1;
}

int SD_Transfer_write(char *FileName,u32 SourceAddress,u32 ByteLength)
{
    FIL fil;
    FRESULT rc;
    UINT bw;

    rc = f_open(&fil,FileName,FA_CREATE_ALWAYS | FA_WRITE);
    if(rc)
    {
        xil_printf("ERROR : f_open returned %d\r\n",rc);
        return 0;
    }
    rc = f_lseek(&fil, 0);
    if(rc)
    {
        xil_printf("ERROR : f_lseek returned %d\r\n",rc);
        return 0;
    }
    rc = f_write(&fil,(void*) SourceAddress,ByteLength,&bw);
    if(rc)
    {
        xil_printf("ERROR : f_write returned %d\r\n", rc);
        return 0;
    }
    rc = f_close(&fil);
    if(rc){
        xil_printf("ERROR : f_close returned %d\r\n",rc);
        return 0;
    }
    return 1;
}

#define FILE "test.txt"

int main()
{
    init_platform();

    const char src_str[] = "hsp test sd card write and read!";
    u32 len = strlen(src_str);

    SD_Init();
    SD_Transfer_write(FILE,(u32)src_str,(len+1));//当直接指定len时没有写出，需要指定较大的长度才会写出，原因未知

    char dest_str[33];//len<=33
    SD_Init();
    SD_Transfer_read(FILE,(u32)dest_str,(len+1));

    xil_printf("%s\r\n",dest_str);
    print("SD write and read over!\r\n");

    cleanup_platform();
    return 0;
}

