module;

#include "Engine/Core/Defines.hpp"

#include <string>

export module CopiumEngine.Graphics.GraphicsTypes;

import CopiumEngine.Core.CoreTypes;


namespace Copium
{
    inline constexpr uint32 k_InvalidHandle = 0xffff'ffff;
}


export namespace Copium
{

    enum class ShaderHandle    : uint32 { Invalid = k_InvalidHandle };
    enum class SwapchainHandle : uint32 { Invalid = k_InvalidHandle };


    // TODO(v.matushkin): Add Default color/depth formats that depends on the current platform
    enum class RenderTextureFormat : uint8
    {
        BGRA32,
        Depth32,
    };

    enum class BlendFactor : uint8
    {
        Zero,
        One,
        SrcColor,
        OneMinusSrcColor,
        DstColor,
        OneMinusDstColor,
        SrcAlpha,
        OneMinusSrcAlpha,
        DstAlpha,
        OneMinusDstAlpha,
        ScrAlphaSaturate,
        // TODO(v.matushkin): How this '*1*' values work?
        Src1Color,
        OneMinusSrc1Color,
        Src1Alpha,
        OneMinusSrc1Alpha,
    };


    struct ShaderDesc
    {
        std::string Name;
        std::string VertexSource;
        std::string FragmentSource;
    };

    struct SwapchainDesc
    {
        uint64              WindowNativeHandle;
        uint16              Width;
        uint16              Height;
        uint8               BufferCount;
        RenderTextureFormat Format;
    };

} // export namespace Copium
