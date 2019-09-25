#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/// Representation of an RGB pixel (Red, Green, Blue)
typedef struct {
    union{
        uint8_t r;
        uint8_t red;
    };
    union{
        uint8_t g;
        uint8_t green;
    };
    union{
        uint8_t b;
        uint8_t blue;
    };
}rgb_t __attribute__((aligned(1)));

typedef enum {
        RGB_AliceBlue=0xF0F8FF,
        RGB_Amethyst=0x9966CC,
        RGB_AntiqueWhite=0xFAEBD7,
        RGB_Aqua=0x00FFFF,
        RGB_Aquamarine=0x7FFFD4,
        RGB_Azure=0xF0FFFF,
        RGB_Beige=0xF5F5DC,
        RGB_Bisque=0xFFE4C4,
        RGB_Black=0x000000,
        RGB_BlanchedAlmond=0xFFEBCD,
        RGB_Blue=0x0000FF,
        RGB_BlueViolet=0x8A2BE2,
        RGB_Brown=0xA52A2A,
        RGB_BurlyWood=0xDEB887,
        RGB_CadetBlue=0x5F9EA0,
        RGB_Chartreuse=0x7FFF00,
        RGB_Chocolate=0xD2691E,
        RGB_Coral=0xFF7F50,
        RGB_CornflowerBlue=0x6495ED,
        RGB_Cornsilk=0xFFF8DC,
        RGB_Crimson=0xDC143C,
        RGB_Cyan=0x00FFFF,
        RGB_DarkBlue=0x00008B,
        RGB_DarkCyan=0x008B8B,
        RGB_DarkGoldenrod=0xB8860B,
        RGB_DarkGray=0xA9A9A9,
        RGB_DarkGrey=0xA9A9A9,
        RGB_DarkGreen=0x006400,
        RGB_DarkKhaki=0xBDB76B,
        RGB_DarkMagenta=0x8B008B,
        RGB_DarkOliveGreen=0x556B2F,
        RGB_DarkOrange=0xFF8C00,
        RGB_DarkOrchid=0x9932CC,
        RGB_DarkRed=0x8B0000,
        RGB_DarkSalmon=0xE9967A,
        RGB_DarkSeaGreen=0x8FBC8F,
        RGB_DarkSlateBlue=0x483D8B,
        RGB_DarkSlateGray=0x2F4F4F,
        RGB_DarkSlateGrey=0x2F4F4F,
        RGB_DarkTurquoise=0x00CED1,
        RGB_DarkViolet=0x9400D3,
        RGB_DeepPink=0xFF1493,
        RGB_DeepSkyBlue=0x00BFFF,
        RGB_DimGray=0x696969,
        RGB_DimGrey=0x696969,
        RGB_DodgerBlue=0x1E90FF,
        RGB_FireBrick=0xB22222,
        RGB_FloralWhite=0xFFFAF0,
        RGB_ForestGreen=0x228B22,
        RGB_Fuchsia=0xFF00FF,
        RGB_Gainsboro=0xDCDCDC,
        RGB_GhostWhite=0xF8F8FF,
        RGB_Gold=0xFFD700,
        RGB_Goldenrod=0xDAA520,
        RGB_Gray=0x808080,
        RGB_Grey=0x808080,
        RGB_Green=0x00FF00,
        RGB_GreenYellow=0xADFF2F,
        RGB_Honeydew=0xF0FFF0,
        RGB_HotPink=0xFF69B4,
        RGB_IndianRed=0xCD5C5C,
        RGB_Indigo=0x4B0082,
        RGB_Ivory=0xFFFFF0,
        RGB_Khaki=0xF0E68C,
        RGB_Lavender=0xE6E6FA,
        RGB_LavenderBlush=0xFFF0F5,
        RGB_LawnGreen=0x7CFC00,
        RGB_LemonChiffon=0xFFFACD,
        RGB_LightBlue=0xADD8E6,
        RGB_LightCoral=0xF08080,
        RGB_LightCyan=0xE0FFFF,
        RGB_LightGoldenrodYellow=0xFAFAD2,
        RGB_LightGreen=0x90EE90,
        RGB_LightGrey=0xD3D3D3,
        RGB_LightPink=0xFFB6C1,
        RGB_LightSalmon=0xFFA07A,
        RGB_LightSeaGreen=0x20B2AA,
        RGB_LightSkyBlue=0x87CEFA,
        RGB_LightSlateGray=0x778899,
        RGB_LightSlateGrey=0x778899,
        RGB_LightSteelBlue=0xB0C4DE,
        RGB_LightYellow=0xFFFFE0,
        RGB_Lime=0x00FF00,
        RGB_LimeGreen=0x32CD32,
        RGB_Linen=0xFAF0E6,
        RGB_Magenta=0xFF00FF,
        RGB_Maroon=0x800000,
        RGB_MediumAquamarine=0x66CDAA,
        RGB_MediumBlue=0x0000CD,
        RGB_MediumOrchid=0xBA55D3,
        RGB_MediumPurple=0x9370DB,
        RGB_MediumSeaGreen=0x3CB371,
        RGB_MediumSlateBlue=0x7B68EE,
        RGB_MediumSpringGreen=0x00FA9A,
        RGB_MediumTurquoise=0x48D1CC,
        RGB_MediumVioletRed=0xC71585,
        RGB_MidnightBlue=0x191970,
        RGB_MintCream=0xF5FFFA,
        RGB_MistyRose=0xFFE4E1,
        RGB_Moccasin=0xFFE4B5,
        RGB_NavajoWhite=0xFFDEAD,
        RGB_Navy=0x000080,
        RGB_OldLace=0xFDF5E6,
        RGB_Olive=0x808000,
        RGB_OliveDrab=0x6B8E23,
        RGB_Orange=0xFFA500,
        RGB_OrangeRed=0xFF4500,
        RGB_Orchid=0xDA70D6,
        RGB_PaleGoldenrod=0xEEE8AA,
        RGB_PaleGreen=0x98FB98,
        RGB_PaleTurquoise=0xAFEEEE,
        RGB_PaleVioletRed=0xDB7093,
        RGB_PapayaWhip=0xFFEFD5,
        RGB_PeachPuff=0xFFDAB9,
        RGB_Peru=0xCD853F,
        RGB_Pink=0xFFC0CB,
        RGB_Plaid=0xCC5533,
        RGB_Plum=0xDDA0DD,
        RGB_PowderBlue=0xB0E0E6,
        RGB_Purple=0x800080,
        RGB_Red=0xFF0000,
        RGB_RosyBrown=0xBC8F8F,
        RGB_RoyalBlue=0x4169E1,
        RGB_SaddleBrown=0x8B4513,
        RGB_Salmon=0xFA8072,
        RGB_SandyBrown=0xF4A460,
        RGB_SeaGreen=0x2E8B57,
        RGB_Seashell=0xFFF5EE,
        RGB_Sienna=0xA0522D,
        RGB_Silver=0xC0C0C0,
        RGB_SkyBlue=0x87CEEB,
        RGB_SlateBlue=0x6A5ACD,
        RGB_SlateGray=0x708090,
        RGB_SlateGrey=0x708090,
        RGB_Snow=0xFFFAFA,
        RGB_SpringGreen=0x00FF7F,
        RGB_SteelBlue=0x4682B4,
        RGB_Tan=0xD2B48C,
        RGB_Teal=0x008080,
        RGB_Thistle=0xD8BFD8,
        RGB_Tomato=0xFF6347,
        RGB_Turquoise=0x40E0D0,
        RGB_Violet=0xEE82EE,
        RGB_Wheat=0xF5DEB3,
        RGB_White=0xFFFFFF,
        RGB_WhiteSmoke=0xF5F5F5,
        RGB_Yellow=0xFFFF00,
        RGB_YellowGreen=0x9ACD32,

        // LED RGB color that roughly approximates
        // the color of incandescent fairy lights,
        // assuming that you're using FastLED
        // color correction on your LEDs (recommended).
        RGB_FairyLight=0xFFE42D,
        // If you are using no color correction, use this
        RGB_FairyLightNCC=0xFF9D2A
}CRGB;

static inline rgb_t color_to_rgb(CRGB color){
    rgb_t rgb;
    memset(&rgb, 0, sizeof(rgb_t));
    rgb.red = (uint8_t)(color >> 16 & 0xFF);
    rgb.green = (uint8_t)(color >> 8 & 0xFF);
    rgb.blue = (uint8_t)(color & 0xFF);

    return rgb;
}

#endif
