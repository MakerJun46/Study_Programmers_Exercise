/* ========================================================================= *
 *                                                                           *
 *                               OpenMesh                                    *
 *           Copyright (c) 2001-2015, RWTH-Aachen University                 *
 *           Department of Computer Graphics and Multimedia                  *
 *                          All rights reserved.                             *
 *                            www.openmesh.org                               *
 *                                                                           *
 *---------------------------------------------------------------------------*
 * This file is part of OpenMesh.                                            *
 *---------------------------------------------------------------------------*
 *                                                                           *
 * Redistribution and use in source and binary forms, with or without        *
 * modification, are permitted provided that the following conditions        *
 * are met:                                                                  *
 *                                                                           *
 * 1. Redistributions of source code must retain the above copyright notice, *
 *    this list of conditions and the following disclaimer.                  *
 *                                                                           *
 * 2. Redistributions in binary form must reproduce the above copyright      *
 *    notice, this list of conditions and the following disclaimer in the    *
 *    documentation and/or other materials provided with the distribution.   *
 *                                                                           *
 * 3. Neither the name of the copyright holder nor the names of its          *
 *    contributors may be used to endorse or promote products derived from   *
 *    this software without specific prior written permission.               *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED *
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A           *
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER *
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  *
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,       *
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR        *
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    *
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING      *
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS        *
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              *
 *                                                                           *
 * ========================================================================= */

#include <iostream>
#define no_init_all
#include <Windows.h>
 // -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
 // -------------------- OpenMesh

 //--------------------- allquadrics
#include "quadricfitting.h"
#include "view.h"
#include <fstream>
#include <map>
 //--------------------- allquadrics
#include <numeric>

using namespace allquadrics;
using namespace std;

extern "C" { FILE __iob_func[3] = { *stdin,*stdout,*stderr }; }

// ----------------------------------------------------------------------------

typedef OpenMesh::PolyMesh_ArrayKernelT<>  MyMesh;



// ----------------------------------------------------------------------------
// Build a simple cube and write it to std::cout

void outputQuadric(allquadrics::Quadric &q) {
	cout << q.q[0];
	for (int ii = 1; ii < 10; ii++) {
		cout << ", " << q.q[ii];
	}
}

// ----------------------------------------------------------------------------
// 사이각을 구하기 위한 함수
#define M_PI 3.14159

double angle(MyMesh::Point p1, MyMesh::Point p_target, MyMesh::Point p2)
{
	vec3 a(p1[0], p1[1], p1[2]);
	vec3 x(p_target[0], p_target[1], p_target[2]);
	vec3 b(p2[0], p2[1], p2[2]);

	a -= x;
	b -= x;

	double rad = acos(a * b / (a.length() * b.length()));

	double deg = rad * 180 / M_PI;

	return deg;
}

void angle_Update(vector<pair<MyMesh::VertexHandle, MyMesh::Point>> &holes, vector<pair<int, double>> &index_angles)
{
	index_angles.clear();
	for (int i = 0; i < holes.size(); i++)
	{
		if (i == 0)
		{
			index_angles.push_back(make_pair(i, angle(holes[holes.size() - 1].second, holes[i].second, holes[i + 1].second)));
		}
		else if (i == holes.size() - 1)
		{
			index_angles.push_back(make_pair(i, angle(holes[i - 1].second, holes[i].second, holes[0].second)));
		}
		else
		{
			index_angles.push_back(make_pair(i, angle(holes[i - 1].second, holes[i].second, holes[i + 1].second)));
		}
	}
}

// ----------------------------------------------------------------------------
// 각도에 따라 정렬 compare 함수

bool cmpSecond(pair<int, double> a, pair<int, double> b)
{
	return a.second < b.second;
}

// ----------------------------------------------------------------------------


bool sorting_points(MyMesh mesh, MyMesh::Point a, MyMesh::Point b)
{
	return true;
}

// ----------------------------------------------------------------------------


int main(int argc, char* argv[])
{

	//==============================================openmesh==============================================//
	MyMesh mesh;

	// generate vertices

	MyMesh::VertexHandle vhandle[9];

	vhandle[0] = mesh.add_vertex(MyMesh::Point(-1, -1, 1));
	vhandle[1] = mesh.add_vertex(MyMesh::Point(1, -1, 1));
	vhandle[2] = mesh.add_vertex(MyMesh::Point(1, 1, 1));
	vhandle[3] = mesh.add_vertex(MyMesh::Point(-1, 1, 1));
	vhandle[4] = mesh.add_vertex(MyMesh::Point(-1, -1, -1));
	vhandle[5] = mesh.add_vertex(MyMesh::Point(1, -1, -1));
	vhandle[6] = mesh.add_vertex(MyMesh::Point(1, 1, -1));
	vhandle[7] = mesh.add_vertex(MyMesh::Point(-1, 1, -1));

	// generate (quadrilateral) faces

	std::vector<MyMesh::VertexHandle>  face_vhandles;

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[3]);
	mesh.add_face(face_vhandles);


	face_vhandles.clear();
	face_vhandles.push_back(vhandle[7]);
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[5]);
	face_vhandles.push_back(vhandle[4]);
	mesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[4]);
	face_vhandles.push_back(vhandle[5]);
	mesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[5]);
	face_vhandles.push_back(vhandle[6]);
	mesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[3]);
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[7]);
	mesh.add_face(face_vhandles);

	/*
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[3]);
	face_vhandles.push_back(vhandle[7]);
	face_vhandles.push_back(vhandle[4]);
	mesh.add_face(face_vhandles);
	*/

	//==============================================openmesh==============================================//

	//===============================================Save=================================================//
	// write mesh to output.obj
	try
	{
		if (!OpenMesh::IO::write_mesh(mesh, "output2.obj"))
		{
			std::cerr << "Cannot write mesh to file 'output.off'" << std::endl;
			return 1;
		}
	}
	catch (std::exception& x)
	{
		std::cerr << x.what() << std::endl;
		return 1;
	}

	//===============================================Save=================================================//

		// boundary 찾기

	MyMesh mesh_findBoundary;
	if (!OpenMesh::IO::read_mesh(mesh_findBoundary, "../Smoothing/output2.obj"))
	{
		std::cerr << "Error: Cannot read mesh from " << std::endl;
		return 1;
	}
	else
	{
		std::cout << "read mesh complete" << std::endl;
	}

	vector<MyMesh::VertexHandle> vhandle_boundary;

	MyMesh::VertexIter          v_it, v_end(mesh_findBoundary.vertices_end());
	MyMesh::VertexVertexIter    vv_it;

	for (v_it = mesh_findBoundary.vertices_begin(); v_it != v_end; ++v_it)
	{
		if (mesh_findBoundary.is_boundary(v_it))
		{
			MyMesh::Point p = mesh_findBoundary.point(v_it);
			vhandle_boundary.push_back(v_it);
		}
	}

	vector<pair<MyMesh::VertexHandle, MyMesh::Point>> holes;	// vertexhandle, points
	vector<pair<int, double>> index_angles; // point index, andgles;
	//--------------------------------------------------- boundary로 찾은 vertex들을 순서대로 정렬

	holes.push_back(make_pair(vhandle_boundary[0], mesh_findBoundary.point(vhandle_boundary[0])));
	auto vertex_startPoint = vhandle_boundary[0];
	auto vertex_tmp = vhandle_boundary[0];
	MyMesh::HalfedgeHandle connected_halfEdge = mesh_findBoundary.halfedge_handle(vertex_tmp);
	MyMesh::VertexHandle next_v = mesh_findBoundary.to_vertex_handle(connected_halfEdge);
	vhandle_boundary.erase(vhandle_boundary.begin());
	

	while (!vhandle_boundary.empty()) 
	{
		if (vhandle_boundary.size() == 1)
		{
			vertex_tmp = vhandle_boundary[0];
			if (vertex_tmp.idx() == next_v.idx())
			{
				holes.push_back(make_pair(vertex_tmp, mesh_findBoundary.point(vertex_tmp)));
				
				connected_halfEdge = mesh_findBoundary.halfedge_handle(vertex_tmp);
				next_v = mesh_findBoundary.to_vertex_handle(connected_halfEdge);

				if (next_v.idx() == vertex_startPoint.idx())
				{
					cout << "loop 를 확인하고 point를 정상적으로 정렬하였습니다." << endl;
				}
				else
				{
					cout << "Error : loop가 정상적이지 않습니다. 시작점과 끝점이 연결되지 않습니다." << endl;
				}
				break;
			}
			else
			{
				auto p = mesh_findBoundary.point(vertex_tmp);

				cout << "Error : mesh에 포함되지 않은 Vertex가 있습니다. Vertex idx : " << vertex_tmp.idx() << endl;
				cout << "Vertex Coordinate : " << p[0] << " " << p[1] << " " << p[2] << endl;
				return 1;
			}
		}

		for (auto it = vhandle_boundary.begin(); it != vhandle_boundary.end(); it++)
		{
			if (next_v.idx() == it->idx())
			{
				holes.push_back(make_pair(*it, mesh_findBoundary.point(*it)));
				vertex_tmp = *it;

				connected_halfEdge = mesh_findBoundary.halfedge_handle(vertex_tmp);
				next_v = mesh_findBoundary.to_vertex_handle(connected_halfEdge);

				vhandle_boundary.erase(it);
				break;
			}
		}
	}
	//--------------------------------------------------- boundary로 찾은 vertex들을 순서대로 정렬


	for (auto i : holes)
	{
		cout << i.first << "번의 좌표" << endl;
		cout << i.second[0] << "\t" << i.second[1] << "\t" << i.second[2] << endl;
	}
	

	//--------------------------------------------------- vertex 간의 사이각 계산

	for (int i = 0; i < holes.size(); i++)
	{
		if (i == 0)
		{		
			index_angles.push_back(make_pair(i, angle(holes[holes.size() - 1].second, holes[i].second, holes[i + 1].second)));
		}
		else if (i == holes.size() - 1)
		{
			index_angles.push_back(make_pair(i, angle(holes[i - 1].second, holes[i].second, holes[0].second)));
		}
		else
		{
			index_angles.push_back(make_pair(i, angle(holes[i - 1].second, holes[i].second, holes[i + 1].second)));
		}
	}
	//--------------------------------------------------- vertex 간의 사이각 계산

	for (auto i : index_angles)
	{
		cout << i.first <<  "번 사이각 : " << i.second << endl;
	}
	//--------------------------------------------------- 사이각에 따라 점을 연결 혹은 새로운 점 좌표를 생성하여 연결
	vector<vector<MyMesh::VertexHandle>> triangle_Points;
	//now mesh = mesh_findboundary

	sort(index_angles.begin(), index_angles.end(), cmpSecond);

	while (!holes.empty())
	{
		int index = index_angles[0].first;	// 사이각이 가장 작은 개체(내림차순 정렬의 0번째)
		vector<MyMesh::VertexHandle> tmp;

		if (holes.size() == 3) // 점이 3개만 남은 경우 -> 삼각형 1개로 추가
		{
			tmp.push_back(holes[index_angles[0].first].first);
			tmp.push_back(holes[index_angles[1].first].first);
			tmp.push_back(holes[index_angles[2].first].first);

			holes.clear();
			index_angles.clear();
			break;
		}

		if (index_angles[0].second <= 75.1) // 75보다 각이 작은 경우 -> 점 0개 추가, 점 1개 제외, 삼각형 1개 추가
		{
			if (index == 0)
			{
				tmp.push_back(holes[holes.size() - 1].first);
			}
			else
			{
				tmp.push_back(holes[index - 1].first);
			}

			tmp.push_back(holes[index].first);
			tmp.push_back(holes[index + 1].first);

			triangle_Points.push_back(tmp); // 삼각형 추가

			holes.erase(find(holes.begin(), holes.end(), holes[index]));
			index_angles.erase(index_angles.begin());	// 추가 없으니까 그냥 0번째 제거
		}

		else if (75.1 < index_angles[0].second && index_angles[0].second <= 135.1) // 75 < 사이각 < 135 인 경우 -> 점 1개 추가, 점 1개 제외, 삼각형 2개 추가
		{
			if (index == 0)
			{
				vec3 a(holes[holes.size() - 1].second[0], holes[holes.size() - 1].second[1], holes[holes.size() - 1].second[2]);
				vec3 b(holes[index + 1].second[0], holes[index + 1].second[1], holes[index + 1].second[2]);

				vec3 new_coord = a + b; // 새로운 점 좌표 (a 벡터 + b 벡터)
				MyMesh::Point new_point(new_coord[0], new_coord[1], new_coord[2]);

				MyMesh::VertexHandle vh_tmp = mesh_findBoundary.add_vertex(new_point); // 새로운 점 생성

				tmp.push_back(holes[holes.size() - 1].first);
				tmp.push_back(holes[index].first);
				tmp.push_back(vh_tmp);				
				triangle_Points.push_back(tmp); // 삼각형 1 추가

				tmp.clear();
				tmp.push_back(vh_tmp);
				tmp.push_back(holes[index].first);
				tmp.push_back(holes[index + 1].first);
				triangle_Points.push_back(tmp); // 삼각형 2 추가

				// 삼각형 추가했으니 holes와 angle의 정보 새 점으로 바꾸기
				holes[index] = make_pair(vh_tmp, new_point);
			}
			else
			{
				vec3 a(holes[index - 1].second[0], holes[index - 1].second[1], holes[index - 1].second[2]);
				vec3 b(holes[index + 1].second[0], holes[index + 1].second[1], holes[index + 1].second[2]);

				vec3 new_coord = a + b; // 새로운 점 좌표 (a 벡터 + b 벡터)
				MyMesh::Point new_point(new_coord[0], new_coord[1], new_coord[2]);

				MyMesh::VertexHandle vh_tmp = mesh_findBoundary.add_vertex(new_point); // 새로운 점 생성

				tmp.push_back(holes[index - 1].first);
				tmp.push_back(holes[index].first);
				tmp.push_back(vh_tmp);
				triangle_Points.push_back(tmp); // 삼각형 1 추가

				tmp.clear();
				tmp.push_back(vh_tmp);
				tmp.push_back(holes[index].first);
				tmp.push_back(holes[index + 1].first);
				triangle_Points.push_back(tmp); // 삼각형 2 추가

				// 삼각형 추가했으니 holes와 angle의 정보 새 점으로 바꾸기
				holes[index] = make_pair(vh_tmp, new_point);
			}


		}

		angle_Update(holes, index_angles); // 사이각 업데이트
		tmp.clear();
		sort(index_angles.begin(), index_angles.end(), cmpSecond);
	}

	//--------------------------------------------------- 사이각에 따라 점을 연결 혹은 새로운 점 좌표를 생성하여 연결

	//--------------------------------------------------- vertex들을 이어서 면으로 만들기

	for (int i = 0; i < triangle_Points.size(); i++)
	{
		vector<MyMesh::VertexHandle> face_h;

		for (int j = 0; j < triangle_Points[i].size(); j++)
		{
			face_h.push_back(triangle_Points[i][j]);
		}
		mesh_findBoundary.add_face(face_h);
	}


	//--------------------------------------------------- vertex들을 이어서 면으로 만들기

	/*
	vhandle[7] = mesh.add_vertex(MyMesh::Point(-1, 1, -1));
	
	std::vector<MyMesh::VertexHandle>  face_vhandles;

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[3]);
	mesh.add_face(face_vhandles);
	*/

	// write mesh to output.obj
	try
	{
		if (!OpenMesh::IO::write_mesh(mesh_findBoundary, "output2_result.obj"))
		{
			std::cerr << "Cannot write mesh to file 'output.off'" << std::endl;
			return 1;
		}
	}
	catch (std::exception& x)
	{
		std::cerr << x.what() << std::endl;
		return 1;
	}

	//============================================allquadrics=============================================//
	/*
	vector<allquadrics::Quadric> qfits;
	fitAllQuadricTypes(data, qfits);
	vector<allquadrics::TriangleMesh> meshes; meshes.resize(qfits.size());

	for (int i = 0; i < qfits.size(); i++)
	{
		outputQuadric(qfits[i]);
	}

	cout << endl << endl;
	*/

	//============================================allquadrics=============================================//
}