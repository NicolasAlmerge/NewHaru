#include "../include/Constants.hpp"
using namespace pdf;


ByteEncoding::~ByteEncoding() {}

const char* SingleByteEncoding::toString() const {
    switch (value) {
        case StandardEncoding: return "StandardEncoding";
        case MacRomanEncoding: return "MacRomanEncoding";
        case WinAnsiEncoding: return "WinAnsiEncoding";
        case FontSpecific: return "FontSpecific";
        case ISO8859_2: return "ISO8859-2";
        case ISO8859_3: return "ISO8859-3";
        case ISO8859_4: return "ISO8859-4";
        case ISO8859_5: return "ISO8859-5";
        case ISO8859_6: return "ISO8859-6";
        case ISO8859_7: return "ISO8859-7";
        case ISO8859_8: return "ISO8859-8";
        case ISO8859_9: return "ISO8859-9";
        case ISO8859_10: return "ISO8859-10";
        case ISO8859_11: return "ISO8859-11";
        case ISO8859_13: return "ISO8859-13";
        case ISO8859_14: return "ISO8859-14";
        case ISO8859_15: return "ISO8859-15";
        case ISO8859_16: return "ISO8859-16";
        case CP1250: return "CP1250";
        case CP1251: return "CP1251";
        case CP1252: return "CP1252";
        case CP1253: return "CP1253";
        case CP1254: return "CP1254";
        case CP1255: return "CP1255";
        case CP1256: return "CP1256";
        case CP1257: return "CP1257";
        case CP1258: return "CP1258";
        case KOI8_R: return "KOI8-R";
    }
}

const char* MultiByteEncoding::toString() const {
    switch (value) {
        case GB_EUC_H: return "GB-EUC-H";
        case GB_EUC_V: return "GB-EUC-V";
        case GBK_EUC_H: return "GBK-EUC-H";
        case GBK_EUC_V: return "GBK-EUC-V";
        case ETen_B5_H: return "ETen-B5-H";
        case ETen_B5_V: return "ETen-B5-V";
        case NINETYms_RKSJ_H: return "90ms-RKSJ-H";
        case NINETYms_RKSJ_V: return "90ms-RKSJ-V";
        case NINETYmsp_RKSJ_H: return "90msp-RKSJ-H";
        case EUC_H: return "EUC-H";
        case EUC_V: return "EUC-V";
        case KSC_EUC_H: return "KSC-EUC-H";
        case KSC_EUC_V: return "KSC-EUC-V";
        case KSCms_UHC_H: return "KSCms-UHC-H";
        case KSCms_UHC_HW_H: return "KSCms-UHC-HW-H";
        case KSCms_UHC_HW_V: return "KSCms-UHC-HW-V";
    }
}
