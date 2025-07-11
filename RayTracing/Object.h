#pragma once

#include "Hit.h"
#include "Ray.h"
#include "Texture.h"

namespace SYC
{
	class Object
	{
	public:
		Color amb;//ambient
		Color diff;//diffuse
		Color spec;//specular
		float alpha = 0.0f;
		float ks = 1.0f;//specular coefficient

		shared_ptr<Texture> ambTexture;
		shared_ptr<Texture> difTexture;

	public:
		Object(const Color& color = Color(1)) 
			: amb(color), diff(color), spec(color)
		{}

	public:
		virtual Hit CheckRayCollision(const Ray& ray) const = 0;
	};
}