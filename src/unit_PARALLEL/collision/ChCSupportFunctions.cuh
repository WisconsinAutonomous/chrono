#ifndef CHC_SUPPORTFUNCTIONS_H
#define CHC_SUPPORTFUNCTIONS_H

__device__ __host__ inline real3 GetSupportPoint_Sphere(const real3 &B, const real3 &n) {
    real3 result = normalize(n);
	return B.x * result;
}
__device__ __host__ inline real3 GetSupportPoint_Triangle(const real3 &A, const real3 &B, const real3 &C, const real3 &n) {
    real dist = dot(A, n);
    real3 point = A;

    if (dot(B, n) > dist) {
        dist = dot(B, n);
        point = B;
    }

    if (dot(C, n) > dist) {
        dist = dot(C, n);
        point = C;
    }

    return point;
}
__device__ __host__ inline real3 GetSupportPoint_Box(const real3 &B, const real3 &n) {
    real3 result = R3(0, 0, 0);
    result.x = sign(n.x)*B.x;
    result.y = sign(n.y)*B.y;
    result.z = sign(n.z)*B.z;
    return result;
}
__device__ __host__ inline real3 GetSupportPoint_Ellipsoid(const real3 &B, const real3 &n) {
    return B * B * n / length(n * B);
}


__device__ __host__ inline real3 GetSupportPoint_Cylinder(const real3 &B, const real3 &n) {
    real3 u = R3(0, 1, 0);
    real3 w = n - (dot(u, n)) * u;
    real3 result;

    if (length(w) != 0) {
        result = sign(dot(u, n)) * B.y * u + B.x * normalize(w);
    } else {
        result = sign(dot(u, n)) * B.y * u;
    }

    return result;
}
__device__ __host__ inline real3 GetSupportPoint_Plane(const real3 &B, const real3 &n) {
    real3 result = B;

    if (n.x < 0)
        result.x = -result.x;

    if (n.y < 0)
        result.y = -result.y;

    return result;
}
__device__ __host__ inline real3 GetSupportPoint_Cone(const real3 &B, const real3 &n) {
    return R3(0, 0, 0);
}



__device__ __host__ inline real3 GetCenter_Sphere() {
    return ZERO_VECTOR;
}
__device__ __host__ inline real3 GetCenter_Triangle(const real3 &A, const real3 &B, const real3 &C) {
    return R3((A.x + B.x + C.x) / 3.0f, (A.y + B.y + C.y) / 3.0f, (A.z + B.z + C.z) / 3.0f);
}
__device__ __host__ inline real3 GetCenter_Box() {
    return ZERO_VECTOR;
}
__device__ __host__ inline real3 GetCenter_Ellipsoid() {
    return ZERO_VECTOR;
}
__device__ __host__ inline real3 GetCenter_Cylinder() {
    return ZERO_VECTOR;
}
__device__ __host__ inline real3 GetCenter_Plane() {
    return ZERO_VECTOR;
}
__device__ __host__ inline real3 GetCenter_Cone() {
    return ZERO_VECTOR;
}
#endif
