/*****************************************************************************
 *
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2011 Artem Pavlenko
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/

#ifndef SHAPE_INDEX_FEATURESET_HPP
#define SHAPE_INDEX_FEATURESET_HPP

// stl
#include <set>
#include <vector>

// mapnik
#include <mapnik/geom_util.hpp>

// boost
#include <boost/scoped_ptr.hpp>

#include "shape_datasource.hpp"
#include "shape_io.hpp"

using mapnik::Featureset;
using mapnik::box2d;
using mapnik::feature_ptr;

template <typename filterT>
class shape_index_featureset : public Featureset
{
public:
    shape_index_featureset(const filterT& filter,
                           shape_io& shape,
                           const std::set<std::string>& attribute_names,
                           std::string const& encoding,
                           std::string const& shape_name,
                           int row_limit);
    virtual ~shape_index_featureset();
    feature_ptr next();

private:
    filterT filter_;
    //int shape_type_;
    shape_io & shape_;
    boost::scoped_ptr<transcoder> tr_;
    std::vector<int> ids_;
    std::vector<int>::iterator itr_;
    std::set<int> attr_ids_;
    mutable box2d<double> feature_ext_;
    mutable int total_geom_size;
    mutable int count_;
    const int row_limit_;
    //no copying
    shape_index_featureset(const shape_index_featureset&);
    shape_index_featureset& operator=(const shape_index_featureset&);
};

#endif // SHAPE_INDEX_FEATURESET_HPP
