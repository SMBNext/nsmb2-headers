#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void            GLvoid;
typedef unsigned int    GLenum;
typedef unsigned char   GLboolean;
typedef unsigned int    GLbitfield;
typedef unsigned short  GLushort;
typedef signed short    GLshort;
typedef signed int      GLint;
typedef unsigned int    GLuint;
typedef float           GLfloat;
typedef int             GLsizei;
typedef int             GLsizeiptr;
typedef float           GLclampf;

#define GL_FALSE                    0
#define GL_TRUE                     1

#define GL_TEXTURE_2D               0x0DE1
#define GL_TEXTURE_DATA_ADDR_DMP    0x6790
#define GL_VERTEX_SHADER            0x8B31
#define GL_GEOMETRY_SHADER_DMP      0x6001
#define GL_PLATFORM_BINARY_DMP      0x6000
#define GL_DMP_FRAGMENT_SHADER_DMP  0xFFFFFFFF
#define GL_PRIMARY_COLOR            0x8577
#define GL_ARRAY_BUFFER             0x8892
#define GL_ELEMENT_ARRAY_BUFFER     0x8893
#define GL_STATIC_DRAW              0x88E4
#define GL_TRIANGLES                0x0004
#define GL_TRIANGLE_STRIP           0x0005
#define GL_TRIANGLE_FAN             0x0006
#define GL_GEOMETRY_PRIMITIVE_DMP   0x6010
#define GL_FLOAT                    0x1406
#define GL_TEXTURE0                 0x84C0
#define GL_PRIMARY_COLOR            0x8577
#define GL_SRC_COLOR                0x0300
#define GL_SRC_ALPHA                0x0302
#define GL_MODULATE                 0x2100
#define GL_REPLACE                  0x1E01
#define GL_TEXTURE_MAG_FILTER       0x2800
#define GL_TEXTURE_MIN_FILTER       0x2801
#define GL_TEXTURE_WRAP_S           0x2802
#define GL_TEXTURE_WRAP_T           0x2803
#define GL_NEAREST                  0x2600
#define GL_LINEAR                   0x2601
#define GL_REPEAT                   0x2901
#define GL_CLAMP_TO_EDGE            0x812F
#define GL_MIRRORED_REPEAT          0x8370
#define GL_COPY_FCRAM_DMP           0x01000000
#define GL_NO_COPY_FCRAM_DMP        0x02000000

#define NN_GX_MEM_FCRAM             0x00010000
#define NN_GX_MEM_VRAMA             0x00020000
#define NN_GX_MEM_VRAMB             0x00030000


void glBindTexture(GLenum target, GLuint texture);
void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params);
void glActiveTexture(GLenum texture);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameteriv(GLenum target, GLenum pname, const GLint* params);
GLuint glCreateProgram();
GLuint glCreateShader(GLenum type);
void glShaderBinary(GLint n, const GLuint* shaders, GLenum binaryformat, const void * binary, GLint length);
void glAttachShader(GLuint program, GLuint shader);
void glDetachShader(GLuint program, GLuint shader);
void glDeleteShader(GLuint shader);
void glBindAttribLocation(GLuint program, GLuint index, const char* name);
void glLinkProgram(GLuint program);
void glUseProgram(GLuint program);
void glDeleteProgram(GLuint program);
int glGetUniformLocation(GLuint program, const char* name);
void glGenBuffers(GLsizei n, GLuint* buffers);
void glBindBuffer(GLenum target, GLuint buffer);
void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
void glEnableVertexAttribArray(GLuint index);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr);
void glFinish();
void glUniform1i(GLint location, GLint x);
void glUniform1f(GLint location, GLfloat x);
void glUniform3i(GLint location, GLint x, GLint y, GLint z);
void glUniform4fv (GLint location, GLsizei count, const GLfloat* v);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void glDeleteTextures(GLsizei n, const GLuint* textures);

#ifdef __cplusplus
}
#endif
