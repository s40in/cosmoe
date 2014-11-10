#ifndef _VESA_GFX_H_
#define _VESA_GFX_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct VESA_Mode_Info
{
    uint16  ModeAttributes      __attribute__((packed));
    uint8   WinAAttributes      __attribute__((packed));
    uint8   WinBAttributes      __attribute__((packed));
    uint16  WinGranularity      __attribute__((packed));
    uint16  WinSize             __attribute__((packed));
    uint16  WinASegment         __attribute__((packed));
    uint16  WinBSegment         __attribute__((packed));
    uint32  WinFuncPtr          __attribute__((packed));
    uint16  BytesPerScanLine    __attribute__((packed));

    uint16  XResolution         __attribute__((packed));
    uint16  YResolution         __attribute__((packed));
    uint8   XCharSize           __attribute__((packed));
    uint8   YCharSize           __attribute__((packed));
    uint8   NumberOfPlanes      __attribute__((packed));
    uint8   BitsPerPixel        __attribute__((packed));
    uint8   NumberOfBanks       __attribute__((packed));
    uint8   MemoryModel         __attribute__((packed));
    uint8   BankSize            __attribute__((packed));
    uint8   NumberOfImagePages  __attribute__((packed));
    uint8   Reserved            __attribute__((packed));

    uint8   RedMaskSize         __attribute__((packed));
    uint8   RedFieldPosition    __attribute__((packed));
    uint8   GreenMaskSize       __attribute__((packed));
    uint8   GreenFieldPosition  __attribute__((packed));
    uint8   BlueMaskSize        __attribute__((packed));
    uint8   BlueFieldPosition   __attribute__((packed));
    uint8   RsvdMaskSize        __attribute__((packed));
    uint8   RsvdFieldPosition   __attribute__((packed));
    uint8   DirectColorModeInfo __attribute__((packed));
    int32   PhysBasePtr         __attribute__((packed));        /* VBE 2.0 Info */
    int32   OffScreenMemOffset  __attribute__((packed));        /* VBE 2.0 Info */
    int16   OffScreenMemSize    __attribute__((packed));        /* VBE 2.0 Info */
    uint8   UnUsed[206]         __attribute__((packed));        /* VBE 2.0 Info */
} VESA_Mode_Info_s;

#define MDATTR_SUPPORTED   (1L<<0)        /* mode supported if set                        */
#define MDATTR_EXTENDED    (1L<<1)        /* optional information available if set        */
#define MDATTR_BIOSOUTPUT  (1L<<2)        /* BIOS output supported if set                 */
#define MDATTR_COLOR       (1L<<3)        /* set if color, clear if monochrome            */
#define MDATTR_GRAPHICS    (1L<<4)        /* set if graphics mode, clear if text mode     */
#define MDATTR_NON_VGA     (1L<<5)        /* (VBE2) non-VGA mode                          */
#define MDATTR_NO_BANKSW   (1L<<6)        /* (VBE2) No bank switching supported           */
#define MDATTR_LINEAR_FB   (1L<<7)        /* (VBE2) Linear framebuffer mode supported     */

typedef struct Vesa_Info
{
    char         VesaSignature[4]       __attribute__((packed));
    int16        VesaVersion            __attribute__((packed));
    char*        OEMStringPtr           __attribute__((packed));
    int32        Capabilities           __attribute__((packed));
    char*        VideoModePtr           __attribute__((packed));
    int16        TotalMemory            __attribute__((packed));
    int16        OEMSoftwareRev         __attribute__((packed));        /* VBE 2.0 Extensions */
    char*        OEMVendorPtr           __attribute__((packed));        /* VBE 2.0 Extensions */
    char*        OEMProductNamePtr      __attribute__((packed));        /* VBE 2.0 Extensions */
    char*        OEMProductRevPtr       __attribute__((packed));        /* VBE 2.0 Extensions */
    uint8        RESERVED[222]          __attribute__((packed));        /* VBE 2.0 Extensions */
    uint8        OEM_DATA[256]          __attribute__((packed));        /* VBE 2.0 Extensions */
} Vesa_Info_s;

int get_vesa_mode_info( VESA_Mode_Info_s* psVesaModeInfo, uint32 nModeNr );
int get_vesa_info( Vesa_Info_s* psVesaInfo, uint16* pnModeList, int nMaxModeCount );
int set_vesa_mode( uint32 nMode );

#ifdef __cplusplus
}
#endif

#endif /* ndef _VESA_GFX_H_ */