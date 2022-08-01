export module CopiumEngine.ECS.Components:Transform;

import :IComponent;
import CopiumEngine.Core.CoreTypes;
import CopiumEngine.ECS.Entity;
import CopiumEngine.Math;

import <vector>;


export namespace Copium
{

    struct Translation final : IComponent
    {
        Float3 Value;
    };

    struct Rotation final : IComponent
    {
        Quaternion Value;
    };

    struct Scale final : IComponent
    {
        float32 Value;
    };


    struct LocalToWorld final : IComponent
    {
        Float4x4 Value;
    };

    struct LocalToParent final : IComponent
    {
        Float4x4 Value;
    };


    struct Parent final : IComponent
    {
        Entity Value;
    };

    struct Child final : IComponent
    {
        std::vector<Entity> Value;
    };

} // export namespace Copium