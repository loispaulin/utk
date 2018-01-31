#include "../../../externals/CImg-1.6.9/CImg.h"
#include "../../parameters/ParamParser_getopt.hpp"

using namespace utk;
using namespace cimg_library;

uint bn_mask[64][64] = {
{ 229, 45, 162, 57, 0, 153, 67, 96, 213, 77, 24, 222, 167, 56, 194, 254, 103, 72, 140, 87, 163, 224, 18, 131, 154, 115, 193, 42, 17, 244, 181, 91, 254, 127, 191, 141, 34, 114, 90, 62, 208, 195, 161, 137, 221, 35, 57, 208, 239, 134, 184, 32, 250, 164, 9, 189, 59, 223, 91, 51, 166, 99, 83, 138 },
{ 145, 186, 212, 119, 177, 200, 30, 128, 54, 151, 179, 106, 13, 139, 32, 156, 173, 1, 197, 248, 53, 188, 76, 233, 89, 9, 177, 62, 221, 150, 68, 116, 28, 154, 60, 218, 16, 163, 178, 130, 0, 240, 117, 69, 184, 97, 148, 81, 24, 69, 216, 87, 56, 20, 230, 208, 154, 116, 24, 146, 70, 249, 178, 45 },
{ 244, 72, 35, 93, 221, 79, 242, 165, 7, 195, 247, 66, 129, 209, 90, 237, 123, 63, 38, 153, 109, 6, 171, 197, 33, 144, 252, 81, 130, 195, 6, 204, 225, 168, 97, 235, 82, 54, 252, 188, 98, 31, 52, 211, 15, 128, 229, 192, 166, 41, 120, 236, 176, 130, 112, 72, 40, 254, 182, 217, 133, 5, 209, 110 },
{ 158, 8, 137, 239, 20, 144, 45, 109, 231, 120, 87, 37, 232, 187, 74, 22, 223, 181, 211, 133, 28, 219, 122, 45, 103, 206, 161, 24, 98, 170, 49, 139, 78, 39, 2, 200, 123, 213, 40, 74, 222, 147, 82, 169, 237, 48, 112, 6, 251, 142, 199, 2, 150, 94, 185, 28, 141, 85, 14, 103, 194, 60, 34, 155 },
{ 192, 205, 104, 168, 64, 194, 90, 181, 27, 206, 50, 146, 171, 10, 114, 144, 45, 106, 78, 93, 237, 61, 140, 248, 71, 227, 53, 120, 215, 33, 233, 103, 249, 187, 111, 176, 21, 138, 155, 10, 172, 122, 248, 198, 27, 156, 73, 180, 95, 53, 106, 66, 211, 46, 243, 221, 171, 204, 49, 237, 161, 123, 223, 80 },
{ 249, 124, 49, 229, 115, 4, 252, 132, 74, 158, 17, 219, 99, 246, 56, 203, 164, 251, 18, 158, 198, 184, 85, 165, 21, 134, 2, 185, 243, 86, 158, 11, 128, 52, 146, 239, 66, 95, 243, 110, 194, 61, 13, 105, 89, 139, 207, 36, 219, 159, 233, 22, 165, 80, 11, 105, 62, 132, 118, 74, 23, 92, 243, 186, },
{ 61, 28, 81, 187, 39, 161, 210, 58, 225, 103, 190, 126, 78, 157, 33, 130, 190, 6, 227, 51, 117, 35, 11, 213, 179, 113, 200, 73, 144, 61, 178, 199, 70, 219, 88, 33, 165, 209, 48, 27, 232, 134, 42, 163, 228, 56, 241, 127, 11, 83, 133, 188, 252, 123, 198, 155, 232, 1, 190, 216, 40, 174, 131, 50 },
{ 220, 179, 143, 214, 127, 96, 148, 13, 35, 176, 241, 61, 1, 211, 229, 87, 66, 100, 141, 173, 73, 245, 102, 146, 58, 93, 231, 39, 107, 16, 212, 116, 22, 156, 194, 8, 226, 121, 78, 203, 90, 179, 70, 216, 186, 22, 115, 168, 64, 204, 31, 112, 40, 144, 55, 88, 35, 168, 96, 250, 149, 206, 14, 67 },
{ 166, 109, 14, 238, 24, 70, 244, 202, 117, 140, 89, 42, 196, 112, 173, 20, 239, 121, 216, 26, 205, 130, 222, 44, 239, 28, 156, 171, 255, 132, 47, 232, 98, 245, 133, 60, 105, 186, 141, 159, 4, 253, 148, 123, 7, 80, 195, 101, 249, 148, 177, 226, 72, 217, 19, 181, 240, 138, 68, 19, 110, 83, 229, 118 },
{ 46, 254, 90, 57, 170, 191, 46, 83, 167, 229, 25, 151, 255, 132, 49, 148, 184, 37, 59, 153, 90, 0, 160, 192, 81, 207, 123, 6, 190, 91, 148, 32, 167, 79, 43, 176, 250, 20, 38, 228, 57, 111, 33, 97, 245, 154, 41, 222, 20, 50, 89, 5, 99, 170, 205, 111, 125, 224, 50, 160, 183, 57, 143, 194 },
{ 31, 156, 134, 201, 113, 232, 102, 134, 5, 67, 209, 180, 94, 16, 70, 105, 222, 81, 197, 253, 109, 178, 67, 116, 13, 139, 64, 217, 77, 226, 56, 184, 205, 13, 118, 201, 149, 71, 99, 127, 189, 210, 167, 52, 201, 129, 178, 75, 140, 191, 238, 160, 128, 245, 64, 9, 77, 29, 197, 213, 9, 247, 37, 102 },
{ 194, 75, 227, 1, 37, 151, 19, 184, 250, 53, 110, 77, 223, 162, 206, 246, 4, 167, 135, 20, 47, 230, 33, 243, 169, 99, 247, 43, 21, 160, 103, 240, 66, 141, 235, 89, 1, 222, 172, 242, 76, 17, 86, 221, 26, 62, 233, 0, 107, 121, 61, 213, 23, 45, 141, 189, 254, 147, 98, 118, 87, 133, 171, 73 },
{ 242, 121, 181, 65, 213, 124, 76, 216, 157, 194, 128, 13, 39, 139, 189, 31, 124, 54, 97, 212, 188, 143, 85, 204, 52, 185, 151, 113, 197, 131, 7, 120, 27, 218, 106, 54, 163, 209, 28, 46, 152, 137, 232, 182, 116, 143, 93, 212, 172, 35, 197, 80, 151, 232, 90, 106, 164, 41, 178, 238, 25, 223, 200, 3 },
{ 21, 104, 48, 163, 88, 176, 237, 42, 96, 30, 242, 171, 231, 116, 62, 88, 152, 181, 228, 73, 118, 8, 157, 128, 18, 223, 30, 81, 173, 211, 250, 87, 154, 178, 192, 36, 135, 122, 63, 113, 199, 6, 103, 39, 160, 16, 255, 47, 153, 242, 14, 104, 180, 31, 201, 56, 215, 3, 70, 154, 60, 45, 111, 235 },
{ 205, 145, 217, 248, 28, 139, 9, 62, 120, 146, 84, 201, 50, 100, 9, 214, 241, 42, 15, 162, 249, 60, 102, 235, 70, 93, 137, 237, 51, 67, 36, 167, 49, 76, 9, 254, 81, 236, 191, 91, 246, 176, 66, 239, 80, 188, 203, 70, 128, 85, 227, 51, 122, 167, 12, 132, 234, 84, 126, 207, 188, 141, 163, 90 },
{ 39, 62, 7, 98, 195, 112, 206, 164, 222, 187, 4, 68, 155, 252, 168, 197, 71, 110, 131, 202, 37, 174, 217, 194, 41, 167, 206, 13, 101, 183, 139, 231, 200, 126, 224, 147, 100, 174, 12, 23, 219, 125, 51, 209, 134, 110, 31, 165, 9, 186, 138, 205, 251, 73, 222, 112, 185, 21, 246, 104, 15, 78, 244, 12 },
{ 110, 241, 130, 156, 80, 52, 254, 74, 23, 238, 108, 132, 219, 19, 123, 142, 27, 235, 149, 94, 81, 24, 139, 113, 3, 253, 123, 158, 221, 116, 2, 92, 21, 110, 60, 27, 205, 45, 157, 141, 73, 165, 26, 151, 3, 227, 57, 98, 220, 113, 61, 26, 93, 147, 39, 63, 158, 139, 50, 171, 228, 36, 211, 108 },
{ 89, 177, 190, 20, 230, 35, 180, 129, 99, 46, 209, 32, 183, 92, 45, 80, 179, 57, 5, 225, 185, 243, 52, 153, 85, 182, 62, 24, 78, 244, 189, 151, 215, 240, 169, 186, 70, 231, 107, 211, 37, 251, 99, 196, 88, 243, 179, 146, 248, 39, 157, 174, 2, 190, 241, 208, 98, 33, 198, 91, 120, 152, 67, 174 },
{ 151, 71, 46, 219, 118, 143, 200, 12, 153, 172, 80, 142, 60, 229, 193, 246, 104, 217, 165, 118, 65, 128, 15, 213, 228, 106, 47, 145, 202, 34, 55, 71, 132, 41, 85, 137, 3, 121, 55, 181, 83, 117, 225, 173, 42, 71, 126, 18, 193, 79, 211, 238, 106, 128, 82, 17, 177, 250, 73, 220, 6, 133, 255, 24 },
{ 122, 252, 13, 103, 170, 64, 91, 244, 57, 226, 119, 248, 159, 0, 114, 33, 157, 18, 198, 42, 101, 204, 171, 72, 33, 192, 240, 130, 175, 99, 163, 252, 14, 102, 209, 152, 248, 92, 198, 237, 7, 133, 61, 15, 140, 112, 215, 51, 92, 7, 123, 68, 45, 162, 218, 55, 118, 145, 23, 162, 59, 182, 99, 47 },
{ 32, 197, 161, 82, 207, 234, 28, 110, 189, 8, 200, 23, 72, 173, 131, 208, 67, 89, 135, 255, 28, 231, 145, 93, 121, 160, 20, 83, 233, 11, 212, 121, 177, 195, 54, 34, 217, 19, 162, 146, 31, 190, 159, 239, 206, 22, 156, 171, 233, 142, 183, 224, 27, 196, 137, 8, 232, 103, 188, 237, 39, 204, 217, 145 },
{ 112, 227, 58, 131, 1, 152, 48, 137, 164, 87, 41, 106, 218, 94, 242, 46, 146, 228, 176, 75, 155, 1, 187, 56, 250, 7, 207, 65, 114, 43, 141, 82, 28, 227, 115, 167, 78, 127, 44, 69, 220, 97, 79, 49, 181, 101, 253, 35, 200, 107, 57, 152, 96, 254, 71, 172, 204, 43, 83, 129, 109, 77, 15, 117 },
{ 7, 93, 178, 37, 248, 183, 223, 76, 213, 237, 149, 133, 54, 196, 13, 183, 108, 8, 54, 194, 113, 86, 45, 134, 218, 100, 180, 152, 223, 194, 59, 237, 156, 68, 8, 243, 191, 104, 178, 255, 112, 201, 10, 122, 223, 84, 61, 134, 74, 24, 245, 13, 178, 112, 36, 89, 156, 61, 214, 4, 154, 243, 175, 92 },
{ 127, 73, 148, 195, 114, 96, 17, 125, 33, 64, 181, 253, 165, 30, 122, 83, 237, 212, 126, 35, 244, 206, 235, 167, 70, 38, 137, 27, 91, 167, 0, 105, 204, 132, 94, 145, 60, 223, 5, 139, 55, 168, 246, 149, 32, 195, 0, 120, 167, 219, 87, 131, 49, 211, 234, 125, 22, 138, 249, 170, 30, 195, 54, 131 },
{ 168, 218, 240, 25, 53, 69, 171, 202, 102, 4, 115, 20, 75, 232, 153, 62, 161, 24, 98, 170, 141, 14, 105, 21, 118, 197, 237, 51, 249, 126, 187, 36, 247, 47, 184, 24, 235, 36, 89, 205, 17, 129, 41, 71, 173, 139, 241, 228, 43, 188, 205, 161, 76, 146, 2, 182, 224, 198, 113, 95, 69, 141, 234, 8 },
{ 62, 16, 85, 137, 211, 233, 145, 250, 158, 191, 225, 89, 210, 138, 203, 39, 190, 250, 72, 221, 61, 157, 79, 184, 227, 149, 80, 110, 15, 213, 75, 147, 87, 172, 211, 122, 108, 165, 150, 74, 182, 228, 106, 218, 90, 18, 109, 154, 95, 9, 117, 33, 241, 194, 62, 105, 79, 52, 11, 229, 45, 209, 104, 84 },
{ 153, 203, 104, 163, 123, 43, 11, 83, 37, 56, 129, 172, 44, 105, 8, 91, 114, 134, 5, 181, 47, 122, 215, 34, 58, 3, 173, 205, 157, 64, 231, 117, 20, 225, 10, 79, 196, 50, 215, 244, 95, 27, 156, 59, 204, 184, 51, 212, 68, 145, 59, 223, 18, 92, 167, 251, 31, 161, 179, 124, 188, 25, 163, 119 },
{ 255, 38, 226, 3, 190, 93, 177, 112, 218, 141, 240, 16, 67, 246, 180, 227, 52, 208, 149, 232, 90, 200, 243, 140, 94, 254, 128, 42, 97, 31, 181, 164, 55, 138, 65, 155, 241, 130, 21, 62, 120, 192, 236, 5, 131, 249, 81, 28, 177, 253, 103, 170, 127, 140, 45, 118, 215, 143, 88, 242, 149, 77, 225, 58 },
{ 92, 54, 175, 75, 247, 62, 231, 23, 198, 73, 97, 160, 193, 124, 145, 25, 167, 80, 33, 107, 19, 168, 9, 111, 161, 68, 187, 222, 143, 246, 5, 101, 195, 254, 94, 30, 181, 101, 2, 173, 144, 42, 77, 169, 115, 38, 162, 231, 123, 197, 41, 79, 232, 205, 6, 187, 235, 20, 64, 36, 108, 0, 196, 130 },
{ 191, 144, 115, 28, 135, 205, 151, 125, 50, 180, 1, 214, 33, 82, 218, 63, 236, 120, 191, 253, 131, 75, 42, 193, 212, 25, 12, 85, 199, 52, 131, 216, 38, 113, 169, 231, 44, 221, 199, 86, 252, 208, 102, 19, 148, 195, 94, 17, 137, 2, 216, 182, 24, 67, 154, 97, 74, 133, 202, 220, 173, 249, 47, 212 },
{ 9, 237, 219, 160, 45, 102, 13, 168, 238, 108, 146, 254, 115, 48, 174, 102, 3, 159, 45, 65, 216, 151, 230, 56, 124, 240, 106, 167, 120, 77, 239, 150, 69, 207, 7, 142, 75, 116, 152, 32, 134, 53, 180, 225, 243, 65, 209, 110, 75, 56, 152, 89, 114, 247, 52, 211, 109, 9, 158, 55, 94, 139, 73, 159 },
{ 108, 65, 17, 87, 186, 214, 80, 35, 221, 88, 26, 60, 133, 202, 20, 248, 136, 203, 95, 173, 26, 185, 101, 86, 177, 146, 47, 234, 28, 176, 14, 90, 183, 22, 126, 190, 56, 246, 166, 68, 229, 7, 126, 90, 32, 50, 142, 186, 247, 165, 236, 34, 135, 194, 163, 37, 179, 255, 119, 190, 26, 236, 115, 31 },
{ 48, 133, 196, 242, 122, 59, 251, 136, 67, 188, 207, 166, 232, 92, 188, 151, 75, 224, 13, 238, 114, 139, 0, 249, 30, 72, 209, 133, 62, 226, 111, 45, 161, 249, 84, 218, 25, 96, 14, 212, 108, 190, 155, 71, 217, 176, 7, 222, 43, 121, 202, 10, 102, 225, 14, 86, 145, 228, 44, 81, 167, 6, 206, 227 },
{ 149, 96, 172, 39, 146, 3, 178, 159, 117, 10, 44, 152, 71, 7, 40, 112, 57, 32, 128, 83, 51, 200, 39, 220, 156, 196, 96, 5, 152, 188, 212, 138, 233, 60, 105, 155, 201, 132, 184, 40, 83, 237, 26, 115, 163, 129, 104, 83, 25, 95, 62, 145, 176, 72, 127, 242, 28, 63, 101, 218, 128, 149, 67, 172 },
{ 10, 233, 23, 74, 223, 109, 28, 199, 94, 245, 224, 104, 180, 123, 240, 215, 171, 192, 156, 210, 246, 164, 77, 129, 113, 17, 173, 251, 81, 35, 98, 197, 6, 120, 35, 175, 48, 232, 118, 147, 171, 56, 204, 255, 15, 196, 242, 153, 173, 229, 189, 253, 42, 217, 56, 168, 196, 136, 204, 18, 248, 39, 106, 242 },
{ 180, 211, 116, 157, 203, 88, 234, 51, 144, 19, 130, 83, 26, 206, 143, 85, 17, 235, 97, 65, 9, 181, 103, 56, 238, 66, 43, 217, 122, 168, 55, 24, 77, 221, 144, 244, 0, 80, 64, 247, 10, 100, 140, 43, 94, 59, 33, 69, 207, 4, 129, 81, 20, 118, 186, 94, 112, 2, 155, 175, 76, 188, 56, 202 },
{ 52, 130, 63, 244, 47, 131, 185, 70, 216, 171, 58, 195, 249, 51, 163, 67, 106, 140, 43, 121, 147, 23, 224, 204, 162, 189, 139, 107, 20, 231, 131, 247, 164, 185, 67, 94, 206, 162, 23, 197, 217, 127, 75, 182, 214, 146, 235, 114, 138, 53, 106, 160, 206, 149, 9, 236, 74, 214, 53, 90, 121, 221, 12, 145 },
{ 252, 92, 190, 5, 103, 21, 165, 36, 106, 237, 0, 155, 112, 35, 224, 5, 254, 182, 27, 229, 195, 85, 134, 33, 14, 92, 242, 74, 180, 205, 89, 149, 104, 210, 29, 129, 113, 227, 137, 87, 35, 156, 229, 3, 168, 82, 187, 17, 219, 168, 36, 238, 91, 224, 49, 31, 141, 252, 38, 228, 25, 161, 95, 179 },
{ 151, 28, 223, 173, 149, 213, 255, 84, 124, 204, 78, 184, 136, 95, 174, 119, 200, 52, 212, 72, 171, 249, 50, 116, 228, 148, 53, 1, 155, 39, 64, 11, 47, 237, 15, 172, 56, 42, 179, 106, 188, 51, 249, 109, 21, 123, 48, 99, 250, 77, 197, 23, 64, 172, 127, 201, 159, 177, 104, 193, 132, 246, 43, 212 },
{ 199, 106, 39, 82, 67, 197, 8, 139, 160, 23, 43, 228, 64, 212, 21, 75, 132, 89, 159, 111, 2, 99, 155, 180, 80, 211, 124, 200, 255, 111, 228, 193, 118, 138, 86, 196, 254, 151, 11, 237, 121, 26, 70, 199, 136, 225, 160, 202, 8, 127, 181, 142, 109, 249, 78, 97, 19, 118, 68, 14, 149, 60, 110, 235 },
{ 177, 232, 141, 122, 239, 52, 114, 179, 61, 248, 101, 148, 9, 246, 191, 152, 233, 12, 242, 142, 38, 217, 67, 236, 9, 39, 172, 95, 27, 134, 167, 217, 76, 161, 36, 213, 100, 74, 222, 60, 165, 209, 95, 176, 58, 241, 26, 68, 152, 95, 56, 218, 0, 39, 189, 229, 57, 208, 243, 85, 170, 202, 75, 30 },
{ 3, 59, 163, 187, 14, 98, 229, 32, 193, 219, 118, 172, 85, 126, 55, 40, 100, 30, 176, 60, 204, 126, 21, 193, 137, 105, 223, 68, 187, 84, 55, 4, 181, 244, 63, 145, 6, 187, 21, 85, 144, 244, 12, 151, 84, 36, 115, 175, 231, 41, 245, 119, 203, 155, 135, 12, 181, 140, 45, 219, 3, 231, 127, 142 },
{ 97, 76, 249, 25, 133, 216, 147, 74, 91, 12, 50, 206, 27, 236, 110, 163, 222, 196, 119, 82, 185, 253, 92, 166, 59, 246, 157, 17, 143, 234, 35, 99, 128, 24, 108, 231, 123, 169, 133, 198, 104, 40, 127, 222, 194, 103, 210, 138, 80, 187, 21, 166, 84, 69, 241, 114, 89, 28, 161, 121, 100, 187, 21, 178 },
{ 227, 119, 37, 201, 85, 173, 41, 166, 238, 135, 157, 188, 72, 143, 180, 209, 69, 136, 48, 229, 15, 150, 46, 115, 26, 79, 207, 49, 120, 195, 249, 153, 204, 222, 51, 194, 91, 43, 249, 218, 27, 77, 182, 49, 1, 164, 254, 52, 10, 206, 147, 100, 31, 220, 48, 168, 213, 234, 75, 195, 58, 39, 90, 213 },
{ 168, 142, 213, 106, 65, 246, 2, 125, 209, 24, 107, 226, 37, 96, 7, 23, 88, 246, 4, 161, 107, 72, 213, 235, 199, 127, 175, 227, 7, 106, 171, 71, 16, 83, 176, 150, 31, 69, 114, 55, 159, 233, 116, 242, 142, 72, 25, 227, 131, 109, 65, 235, 193, 127, 5, 103, 61, 146, 16, 250, 135, 155, 237, 116 },
{ 89, 21, 182, 48, 152, 191, 112, 56, 185, 81, 64, 242, 129, 198, 252, 61, 149, 171, 97, 219, 132, 35, 181, 141, 3, 100, 34, 149, 90, 60, 214, 43, 141, 117, 247, 1, 235, 213, 184, 146, 5, 173, 64, 207, 96, 190, 122, 87, 170, 218, 46, 16, 176, 142, 255, 201, 186, 37, 111, 174, 225, 8, 73, 200 },
{ 218, 72, 243, 8, 128, 224, 30, 94, 254, 148, 5, 169, 48, 156, 112, 217, 124, 39, 192, 58, 243, 19, 168, 85, 53, 251, 67, 186, 241, 26, 130, 232, 189, 95, 61, 161, 135, 100, 82, 23, 201, 90, 135, 31, 15, 156, 59, 200, 35, 151, 249, 91, 116, 57, 80, 19, 158, 130, 84, 207, 49, 107, 185, 30 },
{ 112, 133, 159, 98, 236, 78, 204, 165, 43, 221, 118, 212, 89, 19, 74, 183, 235, 26, 205, 79, 121, 189, 230, 111, 156, 218, 135, 208, 114, 158, 81, 11, 166, 29, 209, 46, 197, 14, 121, 222, 253, 108, 41, 217, 232, 179, 246, 104, 4, 186, 70, 161, 207, 230, 41, 96, 223, 246, 65, 12, 95, 163, 128, 252 },
{ 62, 189, 31, 175, 59, 14, 144, 131, 19, 101, 177, 32, 193, 232, 142, 10, 53, 105, 139, 158, 8, 94, 65, 42, 194, 12, 77, 19, 45, 178, 203, 254, 109, 223, 128, 78, 243, 170, 62, 155, 49, 189, 168, 81, 111, 130, 45, 78, 236, 119, 135, 11, 30, 184, 147, 169, 119, 28, 193, 149, 240, 25, 216, 57 },
{ 93, 253, 207, 43, 119, 215, 182, 67, 197, 233, 73, 137, 57, 100, 208, 166, 85, 176, 240, 46, 213, 255, 148, 28, 226, 122, 166, 104, 228, 142, 58, 37, 69, 152, 9, 104, 183, 37, 229, 129, 73, 10, 243, 150, 57, 12, 205, 145, 23, 211, 225, 83, 103, 245, 68, 3, 211, 53, 177, 220, 116, 68, 202, 83 },
{ 122, 11, 84, 152, 232, 106, 88, 243, 50, 155, 8, 247, 162, 126, 38, 251, 115, 218, 69, 22, 102, 172, 131, 206, 91, 179, 59, 249, 87, 3, 124, 94, 196, 176, 234, 55, 144, 27, 92, 211, 25, 141, 98, 199, 29, 225, 163, 94, 175, 55, 40, 166, 199, 130, 113, 228, 77, 134, 89, 41, 138, 1, 170, 153 },
{ 167, 221, 69, 138, 21, 162, 2, 35, 126, 109, 85, 213, 16, 184, 66, 27, 153, 4, 187, 124, 198, 55, 77, 0, 243, 141, 34, 198, 152, 186, 238, 216, 138, 23, 85, 206, 247, 112, 164, 186, 237, 118, 216, 64, 177, 116, 253, 67, 195, 107, 248, 149, 59, 16, 45, 191, 156, 106, 17, 235, 186, 101, 245, 49 },
{ 47, 102, 197, 180, 52, 250, 189, 210, 172, 228, 190, 43, 117, 236, 81, 199, 132, 93, 227, 147, 35, 237, 115, 162, 49, 109, 72, 220, 27, 50, 167, 14, 114, 46, 158, 122, 5, 66, 200, 80, 53, 1, 160, 38, 134, 88, 7, 139, 33, 127, 0, 182, 90, 216, 238, 174, 33, 253, 207, 164, 75, 31, 222, 130 },
{ 134, 240, 32, 114, 218, 95, 64, 140, 75, 25, 149, 62, 95, 144, 223, 175, 42, 58, 249, 13, 88, 182, 216, 24, 187, 231, 10, 130, 116, 80, 101, 62, 250, 227, 72, 189, 219, 135, 42, 151, 106, 179, 246, 75, 231, 186, 50, 215, 157, 229, 72, 208, 22, 138, 66, 97, 6, 144, 64, 48, 119, 199, 87, 61 },
{ 64, 156, 13, 78, 131, 39, 157, 117, 15, 102, 254, 204, 168, 1, 25, 102, 211, 163, 112, 73, 168, 135, 65, 149, 98, 202, 157, 173, 244, 213, 195, 150, 180, 92, 34, 172, 16, 99, 255, 19, 226, 128, 91, 15, 206, 105, 22, 242, 83, 171, 117, 100, 233, 154, 120, 202, 84, 188, 128, 227, 155, 9, 147, 254 },
{ 91, 248, 170, 204, 236, 7, 194, 241, 222, 182, 33, 132, 52, 245, 124, 70, 234, 138, 29, 204, 222, 43, 9, 252, 79, 39, 60, 92, 17, 41, 133, 30, 1, 209, 141, 107, 235, 60, 168, 209, 31, 194, 144, 56, 167, 150, 125, 199, 59, 11, 41, 189, 52, 29, 248, 168, 40, 111, 245, 16, 175, 215, 107, 41 },
{ 38, 122, 54, 100, 145, 175, 85, 59, 47, 160, 89, 218, 78, 194, 155, 182, 10, 49, 192, 96, 243, 125, 105, 195, 223, 120, 238, 145, 184, 69, 225, 119, 78, 240, 126, 48, 196, 147, 88, 119, 71, 45, 218, 114, 251, 35, 70, 96, 179, 148, 255, 133, 164, 76, 14, 219, 57, 211, 27, 98, 83, 54, 186, 73 },
{ 207, 188, 25, 69, 227, 20, 109, 208, 136, 5, 121, 174, 19, 111, 37, 240, 86, 119, 148, 15, 57, 157, 28, 175, 139, 4, 30, 209, 110, 254, 159, 174, 200, 58, 156, 23, 80, 228, 3, 187, 157, 240, 8, 79, 192, 18, 233, 219, 109, 24, 207, 86, 223, 194, 104, 146, 131, 178, 68, 140, 233, 30, 241, 116 },
{ 0, 108, 220, 162, 46, 126, 252, 150, 73, 236, 202, 64, 227, 97, 140, 59, 200, 225, 172, 78, 185, 213, 86, 49, 68, 163, 190, 82, 53, 11, 94, 46, 103, 15, 218, 249, 179, 37, 133, 52, 103, 173, 138, 95, 177, 130, 161, 44, 139, 237, 56, 8, 114, 37, 241, 90, 3, 236, 195, 161, 203, 126, 170, 150 },
{ 153, 250, 137, 82, 201, 180, 35, 12, 189, 105, 40, 147, 251, 8, 213, 160, 27, 103, 254, 38, 131, 235, 111, 227, 203, 100, 128, 221, 170, 141, 26, 229, 187, 117, 71, 166, 98, 114, 214, 251, 199, 26, 233, 39, 211, 64, 13, 88, 188, 74, 172, 128, 155, 62, 182, 163, 49, 79, 115, 42, 6, 64, 91, 48 },
{ 92, 42, 11, 117, 241, 96, 65, 214, 88, 165, 25, 185, 116, 49, 170, 73, 129, 2, 206, 64, 166, 7, 22, 147, 251, 15, 40, 242, 115, 74, 204, 247, 149, 36, 135, 207, 12, 153, 66, 17, 77, 123, 58, 154, 110, 195, 248, 119, 214, 32, 100, 200, 233, 21, 208, 123, 253, 18, 153, 228, 106, 211, 252, 189 },
{ 211, 170, 192, 57, 28, 154, 171, 231, 125, 243, 56, 83, 133, 196, 92, 245, 182, 46, 115, 143, 94, 197, 75, 119, 181, 90, 62, 153, 2, 182, 129, 59, 84, 5, 241, 90, 47, 189, 237, 142, 94, 164, 220, 4, 83, 229, 52, 144, 6, 158, 251, 45, 142, 95, 72, 31, 197, 138, 94, 186, 25, 76, 139, 36 },
{ 124, 73, 228, 144, 217, 16, 109, 47, 142, 1, 207, 154, 224, 12, 34, 220, 147, 83, 237, 215, 28, 247, 155, 54, 32, 138, 209, 191, 231, 33, 105, 160, 222, 171, 196, 62, 223, 126, 33, 176, 206, 43, 247, 186, 131, 22, 169, 104, 182, 65, 218, 82, 1, 173, 226, 106, 216, 170, 61, 242, 130, 178, 159, 227 },
{ 161, 33, 105, 88, 183, 131, 77, 193, 31, 99, 172, 71, 240, 109, 62, 123, 19, 191, 56, 171, 108, 43, 187, 217, 169, 239, 109, 71, 48, 92, 212, 21, 49, 120, 143, 26, 110, 157, 82, 228, 11, 115, 65, 146, 99, 37, 207, 80, 240, 19, 126, 113, 192, 242, 132, 55, 9, 84, 35, 220, 50, 17, 115, 58 }
};

int main(int argc, char** argv)
{
	srand48(time(NULL));
	
	//PARSE PARAM
	ParamParser_getopt parser;
	std::string param_image;
	parser.addShortOption('i', &param_image, 1, assignString, displayString, (char*)"<string> the image to halftone", (char*)"Image");
	std::string param_output;
	parser.addShortOption('o', &param_output, 1, assignString, displayString, (char*)"<string> the output halftoned image", (char*)"Output");
	uint param_sizematrix = 64;
	parser.addShortOption('s', &param_sizematrix, 1, assignUInt, displayUInt, (char*)"<uint=470> the size of the threshold matrix", (char*)"Matrix size");
	parser.parse(argc, argv);
	
	if(param_image.empty())
	{
		ERROR("Parameter -i mandatory");
		std::cout << parser.getHelp() << std::endl;
		return 1;
	}
	if(param_output.empty())
	{
		ERROR("Parameter -o mandatory");
		std::cout << parser.getHelp() << std::endl;
		return 1;
	}

	double** bluenoise_matrix;
	bluenoise_matrix = new double*[param_sizematrix];
	for(uint i=0; i<param_sizematrix; i++)
		bluenoise_matrix[i] = new double[param_sizematrix];

	for(uint i=0; i<param_sizematrix; i++)
	for(uint j=0; j<param_sizematrix; j++)
		bluenoise_matrix[i][j] = bn_mask[i%64][j%64];
	
	CImg<unsigned char> matrix(param_sizematrix, param_sizematrix, 1, 1);
	for(uint i=0; i<param_sizematrix; i++)
	for(uint j=0; j<param_sizematrix; j++)
		matrix.atXYZC(i, j, 0, 1) = bluenoise_matrix[i][j];
	matrix.save("bluematrix_128.png");

	CImg<unsigned char> m_image = CImg<unsigned char>(param_image.c_str());
	uint m_imgheight = m_image.height();
	uint m_imgwidth = m_image.width();
	uint m_imgchannels = m_image.spectrum();

	/*Convert to BW*/
	for(uint i=0; i<m_imgwidth; i++)
	for(uint j=0; j<m_imgheight; j++)
	{
		int bw_value=0;
		for(uint c=0; c<m_imgchannels; c++)
			bw_value += m_image.atXYZC(i, j, 0, c);
		
		bw_value /= m_imgchannels;

		double threshold = bluenoise_matrix[i%param_sizematrix][j%param_sizematrix];
		if(bw_value > threshold)
			for(uint c=0; c<m_imgchannels; c++)
				m_image.atXYZC(i, j, 0, c) = 255;
		else
			for(uint c=0; c<m_imgchannels; c++)
				m_image.atXYZC(i, j, 0, c) = 0;
	}

	m_image.save(param_output.c_str());
	
	return 0;
}