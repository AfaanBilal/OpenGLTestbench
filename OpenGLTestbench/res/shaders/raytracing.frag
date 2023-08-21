#version 330 core

uniform vec3 u_RayOrigin;

out vec4 color;

void main()
{
	vec3 rayOrigin = u_RayOrigin;
	float x = (gl_FragCoord.x / 800.0f) * 2.0f - 1.0f;
	float y = (gl_FragCoord.y / 800.0f) * 2.0f - 1.0f;
	vec3 rayDirection = vec3(x, y, -1.0f);
	float radius = 0.5f;

	float a = dot(rayDirection, rayDirection);
	float b = 2.0f * dot(rayOrigin, rayDirection);
	float c = dot(rayOrigin, rayOrigin) - radius * radius;

	// Discriminant
	float D = b * b - 4 * a * c;

	// no hits
	if (D < 0)
	{
		color = vec4(0, 0, 0, 1); // black background
	}
	else
	{
		float closeHit = (- b - sqrt(D)) / (2.0f * a);

		vec3 hit = rayOrigin + rayDirection * closeHit;
		vec3 normal = normalize(hit);

		vec3 lightDirection = normalize(vec3(-1, -1, -1));

		float d = max(dot(normal, -lightDirection), 0.0f); // cos(angle) -> clamp to min 0

		//vec3 sphereColor = normal * 0.5f + 0.5f;
		vec3 sphereColor = vec3(1, 0, 1);
		sphereColor *= d;

		color = vec4(sphereColor, 1.0f); 
	}
}
