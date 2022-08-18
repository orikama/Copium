export module CopiumEditor.Editor.ImGuiRenderPass;

import CopiumEngine.Graphics.GraphicsTypes;
import CopiumEngine.Graphics.RenderGraph;


export namespace Copium
{

    class ImGuiRenderPass final : public IRenderPass
    {
    public:
        ImGuiRenderPass();
        ~ImGuiRenderPass() = default;

        ImGuiRenderPass(ImGuiRenderPass&& other) noexcept = default;
        ImGuiRenderPass& operator=(ImGuiRenderPass&& other) noexcept = default;

        void OnSchedule(RenderGraph& renderGraph) override;
        void OnCreate(RenderGraph& renderGraph) override;
        void OnRender(RenderContext& renderContext) override;

    private:
        RenderGraphTextureID m_engineColorId;
        RenderGraphTextureID m_editorColorId;

        SwapchainHandle      m_swapchainHandle;
        RenderPassHandle     m_renderPassHandle;
        RenderTextureHandle  m_engineColorHandle;
        RenderTextureHandle  m_editorColorHandle;
    };

} // export namespace Copium
