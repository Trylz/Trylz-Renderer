//========================================================================
// Copyright (c) Yann Clotioloman Yeo, 2018
//
//	Author					: Yann Clotioloman Yeo
//	E-Mail					: nebularender@gmail.com
//========================================================================

#pragma once

#include "Graphics/Texture/ImageImpl.h"
#include "Graphics/Vertex.h"
#include <vector>

#define TGRAPHIC_ALLOC_PARAMETER_LIST typename TextureHandle,\
									  typename VertexBufferHandle,\
									  typename IndexBufferHandle

#define TGRAPHIC_ALLOC_PARAMETERS TextureHandle,  \
								  VertexBufferHandle, \
								  IndexBufferHandle

namespace Graphics { namespace Renderer { namespace Realtime
{
template <TGRAPHIC_ALLOC_PARAMETER_LIST>
class TGraphicResourceAllocator
{
public:
	virtual void createTexture2D(const Texture::Image* image, TextureHandle& dst) = 0;

	virtual void createTextureCube(const std::vector<const Texture::Image*>& images, TextureHandle& dst) = 0;
	virtual void releaseTexture(const TextureHandle& textureHandle) const = 0;

	virtual nbBool createVertexBuffer(const void* data, VertexBufferHandle& dst, nbUint32 sizeofElem, nbUint32 count) = 0;;
	virtual void releaseVertexBuffer(const VertexBufferHandle& arrayBufferHandle) const = 0;

	virtual nbBool createIndexBuffer(const std::vector<nbUint32>& data, IndexBufferHandle& dst) = 0;
	virtual void releaseIndexBuffer(const IndexBufferHandle& arrayBufferHandle) const = 0;

	template<typename T>
	nbBool createVertexBuffer(const std::vector<T>& data, VertexBufferHandle& dst)
	{
		return createVertexBuffer(data.data(), dst, sizeof(T), (nbUint32)data.size());
	}
};

template <TGRAPHIC_ALLOC_PARAMETER_LIST>
extern TGraphicResourceAllocator<TGRAPHIC_ALLOC_PARAMETER_LIST>* GraphicResourceAllocatorPtr = nullptr;
}}}